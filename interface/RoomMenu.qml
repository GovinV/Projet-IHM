import QtQuick 2.4

import QtQuick 2.4
import QtQuick.Controls 2.3

RoomMenuForm {
    id: roomMenu
    width: 1280
    height: 800

    property bool host: true
    property string name: "test Server"
    property string serverId: "123456789"
    property int player: 1
    property int playerMax: 4

    Rectangle {
        id: gameMode
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        transformOrigin: Item.Center
        color: "#272727"
        radius: 20

        visible: parent.host

        Text {
            id: text1
            x: 76
            y: 150
            Text {
                  id: salonName
                  y: -113
                  text: qsTr("Nom du Salon")
                  anchors.horizontalCenterOffset: 0
                  font.bold: true
                  font.family: "Tahoma"
                  font.pixelSize: 13
                  verticalAlignment: Text.AlignVCenter
                  horizontalAlignment: Text.AlignHCenter
                  anchors.horizontalCenter: parent.horizontalCenter
                  color: "#ffffff"
              }
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }

        Rectangle
        {
            x: 62
            y: 69
            width: 158
            height: 75
            anchors.horizontalCenter: parent.horizontalCenter
            color: "#dddddd"
            TextInput {
                id: textInput
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                wrapMode: TextEdit.WordWrap
                color: "#000000"
                text: qsTr("Salon heberger par " + settingsForm.nicknameInput)
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
                //validator: RegExpValidator { regExp: /[0-9a-zA-Z]{1,30}/ }
            }
        }

        Text {
            id: text2
            x: 76
            y: 150
            Text {
                  id: nbtxt
                  text: qsTr("Nombre de joeurs (2-4)")
                  font.bold: true
                  font.family: "Tahoma"
                  font.pixelSize: 13
                  verticalAlignment: Text.AlignVCenter
                  horizontalAlignment: Text.AlignHCenter
                  anchors.horizontalCenter: parent.horizontalCenter
                  anchors.verticalCenter: parent.verticalCenter
                  color: "#ffffff"
              }
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }


        SpinBox {
            id: textInput1
            x: 47
            y: 195
            width: 110
            height: 33
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 13
            font.family: "Tahoma"
            to: 4
            from: 2
            value: 4

        }

        Button {
            id: save
            Text {
                  id: saveText
                  text: qsTr("Sauvegarder")
                  font.bold: true
                  font.family: "Tahoma"
                  font.pixelSize: 15
                  verticalAlignment: Text.AlignVCenter
                  horizontalAlignment: Text.AlignHCenter
                  anchors.horizontalCenter: parent.horizontalCenter
                  anchors.verticalCenter: parent.verticalCenter
                  color: "#ffffff"
              }
            width: parent.width
            height: 50
            anchors.bottom: parent.bottom
            anchors.bottomMargin: (parent.parent.width / 2048) * 24
            background: Rectangle{
                color: save.hovered?"#e98515":"#484848"
            }
        }

        Rectangle {
            id: rectangle
            anchors.fill: parent
            radius: 20
            color: "#00000000"
            border.color: "#ffffff"
            border.width: (parent.parent.width / 2048) * 24

        }
    }


    Rectangle {
        id: playerList
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.host?((parent.width / 2048) * (220)):0
        transformOrigin: Item.Center
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"

        ScrollView {
            id: scrollView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-(parent.parent.width / 2048) * 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * 24


            Flickable {
                clip: true
                Column {
                    id: column
                    width: scrollView.width

                    Player{
                        width: parent.width
                        name: "Semper"
                        isReady: true
                    }
                    Player{
                        width: parent.width
                        name: "Govin"
                        isReady: false
                    }
                }
            }

            Button {
                id: button

                property bool isReady:false

                Text {
                      id: textProfil
                      text: host?qsTr("Demarer"):qsTr("Pret")
                      font.bold: true
                      font.family: "Tahoma"
                      font.pixelSize: 20
                      verticalAlignment: Text.AlignVCenter
                      horizontalAlignment: Text.AlignHCenter
                      anchors.horizontalCenter: parent.horizontalCenter
                      anchors.verticalCenter: parent.verticalCenter
                      color: "#ffffff"
                  }
                width: parent.width
                height: 50
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                background: Rectangle{
                    color: {
                        if(host)
                        {/*
                            if()
                                button.hovered?"#e98515":"#484848";
                            else*/
                                "#484848";
                        }
                        else
                            button.hovered?"#e98515":"#484848";
                    }
                }
            }
        }
    }





}
