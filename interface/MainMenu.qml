import QtQuick 2.4

MainMenuForm {
    id: item1
    width: 1280
    height: 800

    Image {
        id: profil
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
        source: "qrc:/resources/img/menu.png"

    }

    Image {
        id: play
        x: 534
        y: 495
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (440))
        anchors.verticalCenterOffset: 0
        source: "qrc:/resources/img/menu.png"
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        anchors.verticalCenter: parent.verticalCenter

    }

    Image {
        id: custom
        x: 534
        y: 502
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        source: "qrc:/resources/img/menu.png"
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        anchors.verticalCenter: parent.verticalCenter

    }
}
