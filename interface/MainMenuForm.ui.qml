import QtQuick 2.4

Item {
    id: item1
    width: 1280
    height: 800

    Image {
        id: image
        x: 538
        y: 502
        width: 204
        height: 313
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: 1
        anchors.verticalCenter: parent.verticalCenter
        transformOrigin: Item.Center
        source: "qrc:/resources/img/menu.png"
    }

    Image {
        id: image1
        x: 534
        y: 495
        width: 204
        height: 313
        anchors.horizontalCenterOffset: 270
        anchors.verticalCenterOffset: 1
        source: "qrc:/resources/img/menu.png"
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        anchors.verticalCenter: parent.verticalCenter
    }

    Image {
        id: image2
        x: 534
        y: 502
        width: 204
        height: 313
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: -270
        source: "qrc:/resources/img/menu.png"
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        anchors.verticalCenter: parent.verticalCenter
    }
}
