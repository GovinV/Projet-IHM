import QtQuick 2.4
import QtQuick.Controls 2.3

ServerMenuForm {
    id: serverMenu
    width: 1280
    height: 800

    Rectangle {
        id: gameMode
        x: 538
        y: 502
        //width: 204
        //height: 313
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        transformOrigin: Item.Center
        color: "#272727"
        radius: 20

        Button {
            id: soloButton
            x: (parent.parent.width / 2048) * 24
            y: (parent.parent.width / 2048) * 24
            width: parent.width-((parent.parent.width / 2048) * 24*2)
            height: (parent.height-((parent.parent.width / 2048) * 24*2))/3
            background: rgba(0,0,0,0)

            onClicked: {
                swipeHorizontalServeur.setCurrentIndex(1);
                room.host=true;
            }

            Rectangle{
               id: soloBackground
               anchors.fill: parent
               color: "#e98515"
               opacity : 0
            }

             Text {
                 id: soloText
                 color: "white"
                 anchors.fill: parent
                 text: qsTr("Solo")
                 verticalAlignment: Text.AlignVCenter
                 horizontalAlignment: Text.AlignHCenter
                 font.bold: true
                 font.family: "Tahoma"
                 font.pixelSize: 20
             }

             onHoveredChanged: function(){
                if(this.hovered)
                {
                    soloBackground.opacity = 1;
                    //soloText.color="#e98515";
                }
                else
                {
                    soloBackground.opacity = 0;
                    //soloText.color="white";
                }
             }
        }

        Button {
            id: serverButton
            x: (parent.parent.width / 2048) * 24
            y: (parent.parent.width / 2048) * 24+(parent.height-((parent.parent.width / 2048) * 24*2))/3
            width: parent.width-((parent.parent.width / 2048) * 24*2)
            height: (parent.height-((parent.parent.width / 2048) * 24*2))/3
            background: rgba(0,0,0,0)

            onClicked: {
              //  window.close()
            }

            Rectangle{
               id: serverBackground
               anchors.fill: parent
               color: "#e98515"
               opacity : 0
            }

             Text {
                 id: serverText
                 color: "white"
                 anchors.fill: parent
                 text: qsTr("Create Room")
                 verticalAlignment: Text.AlignVCenter
                 horizontalAlignment: Text.AlignHCenter
                 font.bold: true
                 font.family: "Tahoma"
                 font.pixelSize: 20
             }

             onHoveredChanged: function(){
                if(this.hovered)
                {
                    serverBackground.opacity = 1;
                    //tutoText.color="#e98515";
                }
                else
                {
                    serverBackground.opacity = 0;
                    //tutoText.color="white";
                }
             }
        }

        Button {
            id: tutoButton
            x: (parent.parent.width / 2048) * 24
            y: (parent.parent.width / 2048) * 24 + (parent.height-((parent.parent.width / 2048) * 24*2))/3*2
            width: parent.width-((parent.parent.width / 2048) * 24*2)
            height: (parent.height-((parent.parent.width / 2048) * 24*2))/3
            background: rgba(0,0,0,0)

            onClicked: {
              //  window.close()
            }

            Rectangle{
               id: tutoBackground
               anchors.fill: parent
               color: "#e98515"
               opacity : 0
            }

             Text {
                 id: tutoText
                 color: "white"
                 anchors.fill: parent
                 text: qsTr("Tuto")
                 verticalAlignment: Text.AlignVCenter
                 horizontalAlignment: Text.AlignHCenter
                 font.bold: true
                 font.family: "Tahoma"
                 font.pixelSize: 20
             }

             onHoveredChanged: function(){
                if(this.hovered)
                {
                    tutoBackground.opacity = 1;
                    //tutoText.color="#e98515";
                }
                else
                {
                    tutoBackground.opacity = 0;
                    //tutoText.color="white";
                }
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
        id: serverList
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (220))
        transformOrigin: Item.Center
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"

        ScrollView {
            id: scrollView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-60-(parent.parent.width / 2048) * 24
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 60


            Flickable {
                clip: true
                Column {
                    id: column
                    width: scrollView.width

                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 2
                        playerMax: 3
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 3
                        playerMax: 4
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 2
                        playerMax: 2
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 4
                        playerMax: 4
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 1
                        playerMax: 4
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 1
                        playerMax: 2
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 3
                        playerMax: 3
                    }
                    Server{
                        width: parent.width
                        name: "Govin's server"
                        player: 1
                        playerMax: 4
                    }

                }
            }

        }

        Rectangle {
            id: whiteBar
            width: parent.width
            height: 1
            color: "#ffffff"
            anchors.top: parent.top
            anchors.topMargin: 60
        }
    }
}
