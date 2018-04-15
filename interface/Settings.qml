import QtQuick 2.4
import QtQuick.Controls 2.3

SettingsForm {
    width: 300
    height: 710

    Connections{
        target: settings

        onLoadSize: //(int width, int height);
        {
            window.width=width;
            window.height=height;
        }

        onLoadNickname: //(QString mess);
        {

        }

        onLoadLangage: //(QString mess);
        {

        }
    }

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

        Text {
            id: text2
            x: 15
            y: 208
            color: "#ffffff"
            text: qsTr("Fullsscreen")
            font.bold: false
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Text {
            id: text3
            x: 15
            y: 261
            color: "#ffffff"
            text: qsTr("Résolution")
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        CheckBox {
            id: checkBox
            x: 128
            y: 200
            text: qsTr("Check Box")
        }

        ComboBox {
            id: comboBox
            x: 135
            y: 253
        }

        Text {
            id: text4
            x: 55
            y: 322
            color: "#ffffff"
            text: qsTr("Width")
            font.bold: false
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Text {
            id: text5
            x: 194
            y: 322
            color: "#ffffff"
            text: qsTr("Height")
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        TextField {
            id: textField
            x: 46
            y: 359
            width: 71
            height: 40
            text: qsTr("1280")
        }

        TextField {
            id: textField1
            x: 188
            y: 359
            width: 71
            height: 40
            text: qsTr("1080")
        }

        Text {
            id: text6
            x: 15
            y: 118
            color: "#ffffff"
            text: qsTr("Langue")
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        ComboBox {
            id: comboBox1
            x: 135
            y: 110
        }

        Rectangle {
            id: rectangle2
            x: 0
            y: 4
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 173
            anchors.top: parent.top
        }

        Rectangle {
            id: rectangle3
            x: 0
            y: -1
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 426
            anchors.top: parent.top
        }

        Button {
            id: button
            x: 100
            y: 643
            text: qsTr("Sauvegarder")
            font.pointSize: 15
            anchors.horizontalCenterOffset: 75
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 27
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button1
            x: 105
            y: 643
            text: qsTr("Quitter")
            font.pointSize: 15
            anchors.horizontalCenterOffset: -69
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 27
        }
    }
}
