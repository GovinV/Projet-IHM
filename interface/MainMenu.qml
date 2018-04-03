import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQml 2.2
import QtQuick.Controls.Styles 1.4
MainMenuForm {
    id: mainMenuForm
    width: 1280
    height: 800

    Button {
        id: profil
        x: 534
        y: 502
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        anchors.verticalCenter: parent.verticalCenter
        background: rgba(0,0,0,0)

        onClicked: {
            swipeHorizontal.setCurrentIndex(1);
        }

        Image {
            id: profilBackground
            anchors.fill: parent
            source: "qrc:/resources/img/card.png"
        }

        Text {
            id: textProfil
            x: 29
            y: 120
            width: 147
            height: 71
            text: qsTr("Profil")
            font.bold: true
            font.family: "Tahoma"
            rotation: -55
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 50
            color: "#272727"
        }

    }
    Button {
        id: play
        x: 538
        y: 502
        //width: 204
        //height: 313
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        transformOrigin: Item.Center
        background: rgba(0,0,0,0)

        onClicked: {
            swipeVertical.setCurrentIndex(0);
        }

        Image {
            id: playBackground
            anchors.fill: parent
            source: "qrc:/resources/img/card.png"
        }
        Text {
            id: textPlay
            x: 29
            y: 120
            width: 147
            height: 71
            text: qsTr("Play")
            font.bold: true
            font.family: "Tahoma"
            rotation: -55
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 50
            color: "#272727"
        }
    }

    Button {
        id: custom
        x: 534
        y: 495
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (440))
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        anchors.verticalCenter: parent.verticalCenter
        background: rgba(0,0,0,0)

        onClicked: {
            swipeHorizontal.setCurrentIndex(1);
        }

        Image {
            id: customBackground
            anchors.fill: parent
            source: "qrc:/resources/img/card.png"
        }

        Text {
            id: textCustom
            x: 29
            y: 120
            width: 147
            height: 71
            text: qsTr("Editor")
            font.bold: true
            font.family: "Tahoma"
            font.pixelSize: 50
            color: "#272727"
            rotation: -55
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

}
