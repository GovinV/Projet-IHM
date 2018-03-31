import QtQuick 2.4

MenuBarForm {
    width: 1280
    height: 300

    Rectangle {
        id: backgroundGris
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
        id: borderWhite
        x: 0
        y: 85
        width:  parent.width
        height: 12
        color: "#ffffff"
        transformOrigin: Item.TopLeft
    }

    Image {
        id: logo
        x: 0
        y: (parent.width / 2048) * 6
        width: (parent.width / 2048) * 369
        height: (parent.width / 2048) * 300
        transformOrigin: Item.TopLeft
        source: "qrc:/resources/img/logo.png"
    }
}
