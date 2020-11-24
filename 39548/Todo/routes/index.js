const express = require("express");
const router = express.Router();

// Subrouters;
const authRouter = require("./auth");
const userRouter = require("./users");
const todoRouter = require("./todos");

// Mount our subrouters to assemble our apiRouter;
router.use("/auth", authRouter);
router.use("/users", userRouter);
router.use("/todos", todoRouter);

module.exports = router;
