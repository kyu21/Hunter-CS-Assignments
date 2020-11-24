const express = require("express");
const router = express.Router();
const todoController = require("../controllers/todos");

// POST api/todos/
router.route("/").post(todoController.createTodo);

// POST api/todos/:id
router.route("/:id/update").post(todoController.updateTodoById);

// GET api/todos/:id
router.route("/:id/delete").get(todoController.deleteTodoById);

module.exports = router;
