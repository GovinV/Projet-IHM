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
            window.width=width;
            window.height=height;

            if(fullscreenCheckBox.checked)
                window.visibility=Window.FullScreen;
            else
                window.visibility=Window.Windowed;

            widthEdit.text=width;
            heightEdit.text=height;


        }

        onLoadVolume:
        {
            volumeSlider.value=mess;
            playClick.volume=mess;
            playSnap.volume=mess;
        }
        onLoadNickname: //(QString mess);
        {
            nicknameInput.text=mess;
        }

        onLoadLangage: //(QString mess);
        {
            if(mess=="en")
                langageComboBox.currentIndex=1;
            else
                langageComboBox.currentIndex=0;
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
            text: qsTr("Paramètres") + rootItem.emptyString
            anchors.horizontalCenterOffset: 0
            font.bold: true
            font.family: "Tahoma"
            anchors.top: parent.top
            anchors.topMargin: 28
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
            anchors.topMargin: 190
        }

        Text {
            id: fullsscreenText
            x: 15
            y: 293
            color: "#ffffff"
            text: qsTr("Plein écran") + rootItem.emptyString
            font.bold: false
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Text {
            id: text3
            x: 15
            y: 338
            color: "#ffffff"
            text: qsTr("Résolution") + rootItem.emptyString
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        CheckBox {
            id: fullscreenCheckBox
            x: 127
            y: 285
            onCheckedChanged:
            {
                playClick.play();
            }
        }

        ComboBox {
            id: comboBox
            x: 135
            y: 330
            model: ListModel {
                id: cbItems
                ListElement { text: "1280*800"; }
                ListElement { text: "1280*800";}
                ListElement { text: "1280*800";}
                ListElement { text: "Personnalisé";}
            }
        }

        Text {
            id: text4
            x: 55
            y: 392
            color: "#ffffff"
            text: qsTr("Largeur") + rootItem.emptyString
            anchors.horizontalCenterOffset: -67
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: false
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        Text {
            id: text5
            x: 194
            y: 392
            color: "#ffffff"
            text: qsTr("Hauteur") + rootItem.emptyString
            anchors.horizontalCenterOffset: 67
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        Text {
            id: text6
            x: 15
            y: 217
            color: "#ffffff"
            text: qsTr("Langue") + rootItem.emptyString
            font.family: "Tahoma"
            font.bold: false
            font.pixelSize: 20
        }

        ComboBox {
            id: langageComboBox
            x: 135
            y: 209

            model: ListModel {
                id: langueItems
                ListElement { text: "Français";}
                ListElement { text: "English";}
            }

        }

        Rectangle {
            id: rectangle2
            x: 0
            y: 4
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 269
            anchors.top: parent.top
        }

        Rectangle {
            id: rectangle3
            x: 0
            y: -1
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 560
            anchors.top: parent.top
        }



        Rectangle {
            id: rectangle4
            x: 0
            y: 7
            width: 300
            height: 1
            color: "#ffffff"
            anchors.topMargin: 109
            anchors.top: parent.top
        }

        Text {
            id: text7
            x: 15
            y: 136
            width: 92
            height: 29
            color: "#ffffff"
            text: qsTr("Pseudo") + rootItem.emptyString
            verticalAlignment: Text.AlignTop
            font.pixelSize: 20
            font.bold: false
            font.family: "Tahoma"
        }
        Button {
            id: button
            x: 100
            y: 652
            text: qsTr("Réinitialiser") + rootItem.emptyString

            onHoveredChanged:
            {
                if(hovered)
                    playSnap.play();
            }

            background:
                Rectangle {
                    anchors.fill: parent
                    radius: 20
                    color:  button.hovered?"#e98515":"#ffffff"
            }
            onClicked:
            {
                playClick.play();
                settings.loadSettings();
            }
            font.pointSize: 15
            width: settingsForm.width/2.3
            anchors.horizontalCenterOffset: 72
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Button {
            id: button1
            x: 105
            y: 652

            onHoveredChanged:
            {
                if(hovered)
                    playSnap.play();
            }

            background:
                Rectangle {
                    anchors.fill: parent
                    radius: 20
                    color:  button1.hovered?"#e98515":"#ffffff"
            }
            onClicked:
            {
                playClick.play();
                settingsRect.isActive=false;
            }
            text: qsTr("Annuler") + rootItem.emptyString
            width: settingsForm.width/2.3
            font.pointSize: 15
            anchors.horizontalCenterOffset: -72
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 18
        }

        TextInput {
            id: nicknameInput
            x: 135
            y: 139
            width: 140
            height: 24
            selectByMouse: true;
            color: "#e98515"
            text: "anonymous"
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
            anchors.topMargin: 166
            anchors.top: parent.top
        }

        Button {
            id: button2
            x: 31
            y: 589
            height: 34
            width: settingsForm.width/1.1
            text: qsTr("Sauvegarder") + rootItem.emptyString
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 87
            background:
                Rectangle {
                    anchors.fill: parent
                    radius: 20
                    color:  button2.hovered?"#e98515":"#ffffff"
            }

            onHoveredChanged:
            {
                if(hovered)
                    playSnap.play();
            }

            onClicked:
            {
                playClick.play();
                settings.changeNickname(nicknameInput.text);
                //settings.changeLangage();
                settings.changeSize(widthEdit.text,heightEdit.text);
                settings.changeVolume(volumeSlider.value);
                settings.loadSettings();
                if(langageComboBox.currentText=="Français")
                    settings.changeLangage("fr");
                else if(langageComboBox.currentText=="English")
                    settings.changeLangage("en");
            }
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 15
        }

        Rectangle {
            id: rectangle5
            x: 0
            y: 3
            width: 300
            height: 1
            color: "#ffffff"
            anchors.top: parent.top
            anchors.topMargin: 487
        }

        Text {
            id: text8
            x: 15
            y: 512
            color: "#ffffff"
            text: qsTr("Volume") + rootItem.emptyString
            font.pixelSize: 20
            font.family: "Tahoma"
            font.bold: false
        }

        Slider {
            id: volumeSlider
            x: 129
            y: 505
            width: 152
            height: 39
            value: 0.5

        }

        Rectangle {
            id: widthBackground
            x: 48
            y: 426
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
                text: "1280"
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
            x: 182
            y: 426
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
                text: "800"
                font.pixelSize: 15
                selectByMouse: true;
                selectionColor: "#e98515"
                selectedTextColor: "#ffffff"
                validator:IntValidator{bottom: 800; top: 10000;}
                horizontalAlignment: Text.AlignHCenter
            }
        }

    }
}
