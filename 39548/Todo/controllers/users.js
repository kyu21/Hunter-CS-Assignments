const axios = require("axios");
const API_BASE_URL = process.env.API_BASE_URL;

const userController = {
	getAllUsers: getAllUsers,
	getUserByName: getUserByName
};

// GET api/users/
async function getAllUsers(req, res, next) {
	try {
		const users = await axios.get(`${API_BASE_URL}/user`);
		res.status(200).json(users.data);
	} catch (err) {
		console.log(err);
	}
}

// GET api/users/:username
async function getUserByName(req, res, next) {
	try {
		const user = await axios.get(
			`${API_BASE_URL}/user?username=${req.params.username}`
		);
		res.status(200).json(user.data[0]);
	} catch (err) {
		console.log(err);
	}
}

module.exports = userController;
