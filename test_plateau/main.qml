import QtQuick 2.0
import QtQuick.Window 2.1

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    Hand{
        anchors.centerIn: parent
        width: parent.width
    }

    Hand{
        transform: Rotation{origin.x : 0; origin.y: -100; angle: -45}
        anchors.centerIn: parent
        width: parent.width
    }
}
