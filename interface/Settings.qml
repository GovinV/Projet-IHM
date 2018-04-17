import QtQuick 2.7
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

SettingsForm {
    id: settingsForm
    width: 300
    height: 710

    Connections{
        target: settings

        onLoadSize: //(int width, int height);
        {
            window.visibility=Window.Windowed;
            fullscreenCheckBox.checked=false;

            window.width=width;
            window.height=height;

            widthEdit.text=width;
            heightEdit.text=height;


        }

        onLoadNickname: //(QString mess);
        {
            nicknameInput.text=mess;
        }

        onLoadLangage: //(QString mess);
        {

        }

    }

    function changeFullScreen()
    {
        if(fullscreenCheckBox.checked)
            fullscreenCheckBox.checked=false;
        else
            fullscreenCheckBox.checked=true;
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
            anchors.topMargin: 204
        }

        Text {
            id: fullsscreenText
            x: 15
            y: 326
            color: "#ffffff"
            text: qsTr("Fullsscreen")
            font.bold: false
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Text {
            id: text3
            x: 15
            y: 379
            color: "#ffffff"
            text: qsTr("Résolution")
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        CheckBox {
            id: fullscreenCheckBox
            x: 128
            y: 318
            onCheckedChanged:
            {
                if(fullscreenCheckBox.checked)
                    window.visibility=Window.FullScreen;
                else
                    window.visibility=Window.Windowed;
            }
        }

        ComboBox {
            id: comboBox
            x: 135
            y: 371
        }

        Text {
            id: text4
            x: 55
            y: 440
            color: "#ffffff"
            text: qsTr("Width")
            anchors.horizontalCenterOffset: -67
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: false
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Text {
            id: text5
            x: 194
            y: 440
            color: "#ffffff"
            text: qsTr("Height")
            anchors.horizontalCenterOffset: 67
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        Text {
            id: text6
            x: 15
            y: 236
            color: "#ffffff"
            text: qsTr("Langue")
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        ComboBox {
            id: comboBox1
            x: 135
            y: 228
            textRole: ""
        }

        Rectangle {
            id: rectangle2
            x: 0
            y: 4
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 291
            anchors.top: parent.top
        }

        Rectangle {
            id: rectangle3
            x: 0
            y: -1
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 544
            anchors.top: parent.top
        }



        Rectangle {
            id: rectangle4
            x: 0
            y: 7
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 106
            anchors.top: parent.top
        }

        Text {
            id: text7
            x: 15
            y: 145
            width: 92
            height: 29
            color: "#ffffff"
            text: qsTr("Nickname")
            verticalAlignment: Text.AlignTop
            font.pixelSize: 20
            font.bold: false
            font.family: "Tahoma"
        }
        Button {
            id: button
            x: 100
            y: 652
            text: qsTr("Réinitialiser")
            onClicked:
            {
                settings.loadSettings();
            }
            font.pointSize: 15
            anchors.horizontalCenterOffset: 67
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Button {
            id: button1
            x: 105
            y: 652
            onClicked:
            {
                settingsForm.isActive=false;
            }
            text: qsTr("Quitter")
            font.pointSize: 15
            anchors.horizontalCenterOffset: -77
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 18
        }

        TextInput {
            id: nicknameInput
            x: 135
            y: 146
            width: 140
            height: 24
            selectByMouse: true;
            color: "#e98515"
            text: qsTr("Semperfegrhtj")
            selectionColor: "#ffffff"
            selectedTextColor: "#e98515"
            clip:true
            validator: RegExpValidator { regExp: /[0-9a-zA-Z]{1,13}/ }
            horizontalAlignment: Text.AlignLeft
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Rectangle {
            id: nicknameBorder
            x: 135
            y: 8
            width: 140
            height: 1
            color: "#e98515"
            anchors.topMargin: 171
            anchors.top: parent.top
        }

        Button {
            id: button2
            x: 31
            y: 571
            width: 254
            height: 34
            text: qsTr("Sauvegarder")
            onClicked:
            {
                settings.changeNickname(nicknameInput.text);
                //settings.changeLangage();
                settings.changeSize(widthEdit.text,heightEdit.text);
                settings.loadSettings();
            }
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 15
        }
    }

    Rectangle {
        id: widthBackground
        x: 47
        y: 478
        width: 70
        height: 40
        color: "#ffffff"
        anchors.horizontalCenterOffset: -67
        anchors.horizontalCenter: parent.horizontalCenter

        TextInput {
            id: widthEdit
            x: 4
            y: 13
            width: 62
            height: 14
            text: qsTr("1280")
            selectByMouse: true;
            selectionColor: "#e98515"
            selectedTextColor: "#ffffff"
            horizontalAlignment: Text.AlignHCenter
            validator:IntValidator{bottom: 1000; top: 10000;}
            font.pixelSize: 15
        }
    }

    Rectangle {
        id: heightBackground
        x: 189
        y: 478
        width: 70
        height: 40
        color: "#ffffff"
        anchors.horizontalCenterOffset: 67
        anchors.horizontalCenter: parent.horizontalCenter

        TextInput {
            id: heightEdit
            x: 4
            y: 13
            width: 62
            height: 14
            text: qsTr("800")
            font.pixelSize: 15
            selectByMouse: true;
            selectionColor: "#e98515"
            selectedTextColor: "#ffffff"
            validator:IntValidator{bottom: 800; top: 10000;}
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
