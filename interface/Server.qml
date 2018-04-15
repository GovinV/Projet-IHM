import QtQuick 2.4
import QtQuick.Controls 2.3

ServerForm {
    id: serverForm
    width: 600
    height: 60

    property string name: "test Server"
    property string serverId: "123456789"
    property int player: 1
    property int playerMax: 4

    Rectangle {
        id: rectangle1
        x: 0
        width: parent.width
        height: 1
        color: "#ffffff"
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    Button {
        id: button
        x: 492
        y: 10
        text: qsTr("Connect")
        anchors.verticalCenterOffset: 0
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.verticalCenter: parent.verticalCenter

        onClicked: {
            network.joinRoom();
            swipeHorizontalServeur.setCurrentIndex(1);
            room.host=false;
            room.name=name;
            room.serverId=serverId;
            room.player=player;
            room.playerMax=playerMax;
        }

    }

    Text {
        id: text1
        y: 17
        width: 410
        height: 43
        color: "#ffffff"
        text: name
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors.verticalCenterOffset: 1
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 424
        y: 10
        width: 73
        height: 40
        color: player<playerMax?"#3ff826":"#b31919"
        text: player + "/" + playerMax
        anchors.right: parent.right
        anchors.rightMargin: 103
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }
}
