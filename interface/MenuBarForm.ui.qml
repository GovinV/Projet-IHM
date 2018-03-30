import QtQuick 2.4

Item {
    width: 1280
    height: 300

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width:  parent.width
        height: 85
        color: "#272727"
        radius: 0
        border.width: 0
        transformOrigin: Item.TopLeft
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 85
        width:  parent.width
        height: 12
        color: "#ffffff"
        transformOrigin: Item.TopLeft
    }

    Image {
        id: image
        x: 0
        y: 0
        width: 369
        height: 300
        transformOrigin: Item.TopLeft
        source: "qrc:/resources/img/logo.png"
    }
}
