import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "qrc:/resources/img/bg.jpg"
    }

    SwipeView {
        id: swipeView
        currentIndex: 1

        width: parent.width
        height: parent.height-97

        anchors.top: parent.top
        anchors.topMargin: 97

        MainMenu{
            width: parent.width
            height: parent.height
        }
    }

    MenuBar {
        id: menuBarForm
        x: 0
        y: 0
        width: parent.width
        height: 300
    }


}
