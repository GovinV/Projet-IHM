import QtQuick 2.4
import QtQuick.Controls 2.3

CardEditorForm {
    id: cardEditorForm
    width: 1280
    height: 800

    Rectangle {
        id: cardList
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -((parent.width / 2048) * (220))
        transformOrigin: Item.Center
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"

        ScrollView {
            id: scrollView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-60-(parent.parent.width / 2048) * 24
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 60


            Flickable {
                clip: true
                Column {
                    id: column
                    width: scrollView.width

                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 2
                        playerMax: 3
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 3
                        playerMax: 4
                    }
                }
            }
        }
    }

    Card {
        id: card
        x: 894
        y: 377
        width: (parent.parent.width / 2048) * 130
        height: (parent.parent.width / 2048) * 200
        rotation: -15
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 300
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        couleur: "r"
        type: "+2"
    }
    Card {
        id: card2
        x: 894
        y: 377
        width: (parent.parent.width / 2048) * 130
        height: (parent.parent.width / 2048) * 200
        rotation: 15
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 330
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        couleur: "b"
        type: "8"
        style: "s5"
    }
}
