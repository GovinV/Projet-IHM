import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "qrc:/resources/img/background.jpg"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent

        MainMenuForm {
        }
    }
}
