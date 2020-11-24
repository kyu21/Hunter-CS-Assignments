const axios = require("axios");
const API_BASE_URL = process.env.API_BASE_URL;

const todoController = {
	getAllTodos: getAllTodos,
	createTodo: createTodo,
	updateTodoById: updateTodoById,
	deleteTodoById: deleteTodoById
};

// GET /api/todos/
async function getAllTodos(req, res, next) {
	try {
		const response = await axios.get(`${API_BASE_URL}/todo-item`, {
			headers: {
				Cookie: `token=${req.signedCookies.Authentication}`
			}
		});
		return response.data;
	} catch (err) {
		if (err.response.status === 404) {
			return [];
		} else {
			console.log(err);
		}
	}
}

// POST /api/todos/
async function createTodo(req, res, next) {
	try {
		if (req.signedCookies.Authentication === undefined) {
			res.render("error", {
				message: "Error. User not authenticated.",
				error: { status: 401 }
			});
		} else {
			await axios({
				method: "POST",
				url: `${API_BASE_URL}/todo-item`,
				headers: {
					Cookie: `token=${req.signedCookies.Authentication}`
				},
				data: {
					content: req.body.content
				}
			});
			res.status(200).redirect("/todos");
		}
	} catch (err) {
		console.log(err);
	}
}

// POST /api/todos/:id/update
async function updateTodoById(req, res, next) {
	try {
		if (req.signedCookies === undefined) {
			res.render("error", {
				message: "Error. User not authenticated.",
				error: { status: 401 }
			});
		} else {
			await axios({
				method: "PUT",
				url: `${API_BASE_URL}/todo-item/${req.params.id}`,
				headers: {
					Cookie: `token=${req.signedCookies.Authentication}`
				},
				data: {
					completed: req.body.completed === "Done"
				}
			});
			res.status(200).redirect("/todos");
		}
	} catch (err) {
		console.log(err);
	}
}

// GET /api/todos/:id/delete
async function deleteTodoById(req, res, next) {
	try {
		if (req.signedCookies === undefined) {
			res.render("error", {
				message: "Error. User not authenticated.",
				error: { status: 401 }
			});
		} else {
			await axios.delete(`${API_BASE_URL}/todo-item/${req.params.id}`, {
				headers: {
					Cookie: `token=${req.signedCookies.Authentication}`
				}
			});
			res.status(200).redirect("/todos");
		}
	} catch (err) {
		console.log(err);
	}
}

module.exports = todoController;
