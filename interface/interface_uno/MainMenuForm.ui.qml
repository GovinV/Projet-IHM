import QtQuick 2.4

Item {
    id: item1
    width: 1200
    height: 715

    Image {
        id: play
        x: 150
        y: 150
        width: 163
        height: 256
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/resources/img/menu.png"
    }

    Image {
        id: profil
        x: 155
        y: 148
        width: 163
        height: 256
        anchors.horizontalCenterOffset: -250
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: 0
        source: "qrc:/resources/img/menu.png"
        anchors.verticalCenter: parent.verticalCenter
    }

    Image {
        id: custom
        x: 140
        y: 141
        width: 163
        height: 256
        anchors.horizontalCenterOffset: 250
        source: "qrc:/resources/img/menu.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
