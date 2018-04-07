import QtQuick 2.4
import QtQuick.Controls 2.3

SettingsForm {
    width: 300
    height: 710

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#272727"

        Text {
            id: text1
            x: 152
            height: 13
            color: "#e98515"
            text: qsTr("Settings")
            font.bold: true
            font.family: "Tahoma"
            anchors.top: parent.top
            anchors.topMargin: 18
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 35

        }

        Rectangle {
            id: rectangle1
            x: 0
            width: 300
            height: 1
            color: "#ffffff"
            anchors.top: parent.top
            anchors.topMargin: 86
        }
    }
}
