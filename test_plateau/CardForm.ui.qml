import QtQuick 2.4

Item {
    id: item1
    width: 325
    height: 500

    Image {
        id: image
        width: 325
        height: 500
        transformOrigin: Item.TopLeft
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        sourceSize.height: 500
        sourceSize.width: 325
        fillMode: Image.PreserveAspectCrop
        source: "img/cards/0r.png"
    }
}
