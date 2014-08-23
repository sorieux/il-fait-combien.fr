var express = require('express');
var router = express.Router();
var debug = require('debug')('il-fait-combien:');

/* GET home page. */
router.get('/', function(req, res) {
    var db = req.db;
    db.collection('sonde1').find().sort({_id:-1}).limit(1).toArray( function(err, items) {
        res.render('index',items[0]);
    });
});

module.exports = router;
