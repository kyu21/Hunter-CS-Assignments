const axios = require("axios");
const API_BASE_URL = process.env.API_BASE_URL;

const authController = {
	signup: signup,
	login: login,
	logout: logout
};

// POST /api/auth/signup
async function signup(req, res, next) {
	try {
		await axios.post(`${API_BASE_URL}/user`, {
			username: req.body.username
		});
		const response = await axios.post(`${API_BASE_URL}/auth`, {
			username: req.body.username
		});
		res.cookie("Authentication", response.data.token, {
			signed: true,
			httpOnly: true
		});
		res.cookie("user", req.body.username, {
			signed: true,
			httpOnly: true
		});
		res.status(201).redirect("/");
	} catch (err) {
		if (err.response.status === 400) {
			res.status(400).redirect("/");
		} else {
			console.log(err);
		}
	}
}

// POST /api/auth/login
async function login(req, res, next) {
	try {
		const response = await axios.post(`${API_BASE_URL}/auth`, {
			username: req.body.username
		});
		res.cookie("Authentication", response.data.token, {
			signed: true,
			httpOnly: true
		});
		res.cookie("user", req.body.username, {
			signed: true,
			httpOnly: true
		});
		res.status(200).redirect("/");
	} catch (err) {
		if (err.response.status === 400) {
			res.status(400).redirect("/");
		} else {
			console.log(err);
		}
	}
}

// GET /api/auth/logout
async function logout(req, res, next) {
	try {
		res.clearCookie("Authentication");
		res.clearCookie("user");
		res.status(200).redirect("/");
	} catch (err) {
		console.log(err);
	}
}

module.exports = authController;
