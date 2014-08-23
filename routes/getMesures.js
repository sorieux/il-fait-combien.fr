/**
 * Created by Stéphane Orieux on 27/07/2014.
 */
var express = require('express');
var router = express.Router();

/* GET la liste des mesures */
router.get('/', function(req, res) {
    var db = req.db;
    db.collection('sonde1').find().toArray( function(err, items) {
        res.json(items);
    });
});

/* Obtenir le dernier enregistrement */
router.get('/lastRecord', function(req, res) {
    var db = req.db;
    db.collection('sonde1').find().sort({_id:-1}).limit(1).toArray( function(err, items) {
        res.json(items);
    });
});


module.exports = router;