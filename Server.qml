import QtQuick 2.15
import QtWebSockets

Item {
    property int count: 0
    Rectangle{
        anchors.fill: parent
        height: 300
        width: parent.width
        Text{
            id: txtClient
            text: "client"
        }
        Text{
            id: broadcast
            objectName: "broadcast"
            anchors.top: txtClient.bottom
            text: count
        }
    }



    // function appendMessage(message) {
    //     messageBox.text += "\n" + message
    // }

    WebSocketServer {
        id: server
        listen: true
        accept: true

        host: "192.168.1.100"
        port: 1111

        function rec(mess){
            txtClient.text = mess
            console.log(mess + url.toString())
        }

        onClientConnected: function(webSocket) {
            webSocket.onTextMessageReceived.connect(rec)//function(message) {

            webSocket.sendTextMessage("hello client")
            console.log("webSocket.url = " + webSocket.name)
            // for(var i=0;i<listSockets.length;i++)
            //     console.log("s1 = " + listSockets[i])
        }

    }

    WebSocketServer {
        id: serverBroadcast
        listen: true
        accept: true

        host: "192.168.1.100"
        port: 1000

        function rec(mess){
            console.log(mess )//+ count++)
        }

        onClientConnected: function(webSocket) {
            webSocket.onTextMessageReceived.connect(rec)//function(message) {
            console.log("conn")
            //webSocket.sendTextMessage("hello client")
            //console.log("webSocket.url = " + webSocket.name)
            // for(var i=0;i<listSockets.length;i++)
            //     console.log("s1 = " + listSockets[i])
        }

    }

}
