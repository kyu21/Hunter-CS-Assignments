const express = require("express");
const router = express.Router();
const userController = require("../controllers/users");

// GET api/users/
router.route("/").get(userController.getAllUsers);

// GET api/users/:username
router.route("/:username").get(userController.getUserByName);

module.exports = router;
