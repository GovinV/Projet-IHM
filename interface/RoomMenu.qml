import QtQuick 2.4

import QtQuick 2.4
import QtQuick.Controls 2.3

RoomMenuForm {
    id: roomMenu
    width: 1280
    height: 800

    property bool host: true
    property string name: "test Server"
    property string serverId: "123456789"
    property int player: 1
    property int playerMax: 4

    Rectangle {
        id: gameMode
        x: 538
        y: 502
        //width: 204
        //height: 313
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        transformOrigin: Item.Center
        color: "#272727"
        radius: 20

        visible: parent.host

        Rectangle {
            id: rectangle
            anchors.fill: parent
            radius: 20
            color: "#00000000"
            border.color: "#ffffff"
            border.width: (parent.parent.width / 2048) * 24
        }
    }


    Rectangle {
        id: playerList
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.host?((parent.width / 2048) * (220)):0
        transformOrigin: Item.Center
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"

        ScrollView {
            id: scrollView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-(parent.parent.width / 2048) * 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * 24


            Flickable {
                clip: true
                Column {
                    id: column
                    width: scrollView.width

                    Player{
                        width: parent.width
                        name: "Semper"
                        isReady: true
                    }
                    Player{
                        width: parent.width
                        name: "Govin"
                        isReady: false
                    }
                }
            }
        }
    }





}
