import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "qrc:/resources/img/bg.jpg"

        MenuBarForm {
            id: menuBarForm
            x: 0
            y: 0
            width: parent.width
            height: 300
        }
    }
}
