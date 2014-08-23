/**
 * Created by Stéphane Orieux on 26/07/2014.
 */

// DOM Ready
$(document).ready(function() {

    var socket = io.connect('192.1.10.1');
    socket.on('message', function(message) {
        $('.temperature').html(message.temperature+"°C");
    });
});
