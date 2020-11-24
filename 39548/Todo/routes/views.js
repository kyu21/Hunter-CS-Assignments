const express = require("express");
const router = express.Router();
const viewController = require("../controllers/views");

// Get home page
router.route("/").get(viewController.homePage);

// Get signup page
router.route("/signup").get(viewController.signupPage);

// Get login page
router.route("/login").get(viewController.loginPage);

// Get All Todos page
router.route("/todos").get(viewController.allTodosPage);

module.exports = router;
