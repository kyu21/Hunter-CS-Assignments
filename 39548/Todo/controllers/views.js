const todoController = require("./todos");

const viewController = {
	homePage: homePage,
	signupPage: signupPage,
	loginPage: loginPage,
	allTodosPage: allTodosPage
};

// Get home page
async function homePage(req, res, next) {
	try {
		let currUser =
			req.signedCookies.user !== undefined
				? req.signedCookies.user
				: "Not Logged In";
		res.render("home", { user: currUser });
	} catch (err) {
		console.log(err);
	}
}

// Get signup page
async function signupPage(req, res, next) {
	try {
		res.render("signup");
	} catch (err) {
		console.log(err);
	}
}

// Get login page
async function loginPage(req, res, next) {
	try {
		res.render("login");
	} catch (err) {
		console.log(err);
	}
}

// Get all todos page
async function allTodosPage(req, res, next) {
	try {
		if (req.signedCookies.Authentication === undefined) {
			res.render("error", {
				message: "Error. User not authenticated.",
				error: { status: 401 }
			});
		} else {
			const todos = await todoController.getAllTodos(req, res, next);
			const activeTodos = todos
				.map(x =>
					x.completed
						? { ...x, completed: "Done" }
						: { ...x, completed: "Not Done" }
				)
				.filter(x => !x.deleted);
			res.status(200).render("todos", { todos: activeTodos });
		}
	} catch (err) {
		console.log(err);
	}
}

module.exports = viewController;
