const express = require("express");
const router = express.Router();
const authController = require("../controllers/auth");

// POST api/auth/signup
router.route("/signup").post(authController.signup);

// POST api/auth/login
router.route("/login").post(authController.login);

// GET api/auth/logout
router.route("/logout").get(authController.logout);

module.exports = router;
