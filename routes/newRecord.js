/**
 * Created by wen on 20/07/2014.
 */
var express = require('express');
var router = express.Router();

/* POST */
router.post('/', function(req, res) {

    var db = req.db;

    console.log("Requete, body  name: "+req.body.name);
    console.log("Requete, body temperature: "+req.body.temperature);

    // On récuppère le timestamp de l'insertion
    var time = new Date().getTime();

    // On récuppère les variables passées en POST
    var name = req.body.name;
    var temperature = req.body.temperature;

    // Submit to the DB
    db.collection('sonde1').insert({
        "name" : name,
        "temperature" : temperature,
        "timestamp":time
    }, function (err, doc) {

        if (err) {
            // If it failed, return error
            res.send("There was a problem adding the information to the database.");
        }
        else {
            res.send("Success");
            notificationNewRecord({"name":name,"temperature":temperature});

        }
    });
});

module.exports = router;