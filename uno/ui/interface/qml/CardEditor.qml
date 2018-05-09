import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

CardEditorForm {
    id: cardEditorForm
    width: 1280
    height: 800

    property string style: "none"

    function loadUsedStyle()
    {
        style=cardOnBack.style;
        cardOnFront.style=cardOnBack.style;
    }

    Connections{
        target: settings
        onLoadCardStyle: //(QString mess);
        {
            cardOnFront.style=mess;
            cardOnBack.style=mess;
        }
    }
    Rectangle {
        id: cardList
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -((parent.width / 2048) * (220))
        transformOrigin: Item.Center
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"

        ScrollView {
            id: scrollView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-(parent.parent.width / 2048) * 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin:(parent.width / 2048) * 62

            clip: true

                ListModel {
                    id: cardModel

                    ListElement {
                        style: "none"
                    }
                    ListElement {
                        style: "s1"
                    }
                    ListElement {
                        style: "s2"
                    }
                    ListElement {
                        style: "s3"
                    }
                    ListElement {
                        style: "s4"
                    }
                    ListElement {
                        style: "s5"
                    }
                }

                GridLayout {
                    columnSpacing: 0
                    rowSpacing: 20
                    width: scrollView.width
                    height: scrollView.height
                    rows: 2
                    columns: 2

                    onWidthChanged:
                    {
                        if(this.width>500)
                            columns=3;
                        else
                            columns=2;

                    }


                    Repeater {
                        model: cardModel
                        delegate:
                            Rectangle
                            {
                                id: rectangle1
                                width: scrollView.width/2-1
                                height: scrollView.width/2

                                color: Qt.rgba(0,0,0,0)

                                Button {
                                    id: changeStyle
                                    width: ((rectangle1.height-24) / 200) * 130
                                    height: rectangle1.height -24
                                    anchors.verticalCenter: parent.verticalCenter
                                    anchors.horizontalCenter: parent.horizontalCenter

                                    onHoveredChanged:
                                    {
                                        if(hovered)
                                            playSnap.play();
                                    }

                                    onClicked: {
                                        playClick.play();
                                        //cardOnBack.style=model.style;
                                        cardOnFront.style=model.style;
                                        style=model.style;
                                    }

                                    background:
                                        Rectangle{
                                            anchors.fill: parent
                                            color: Qt.rgba(0,0,0,0)
                                            Image {
                                                id: cardBackground
                                                anchors.fill: parent
                                                source: "qrc:/cartes/cartes/b/bg.png"
                                                }
                                            Rectangle {
                                                id: cardBorder
                                                anchors.fill: parent
                                                radius: 20
                                                color: "#00000000"
                                                border.color:  changeStyle.hovered?"#e98515":"#ffffff"
                                                border.width: (width / 325) * 24
                                            }
                                        }

                                    Image {
                                        id: selectedStyle
                                        anchors.fill: parent
                                        source: "qrc:/cartes/cartes/style/"+ model.style +".png"
                                    }
                                }
                            } // Rectangle end
                    }
                }

            }
    }

    Card {
        id: cardOnBack
        x: 894
        y: 377
        width: (parent.parent.width / 2048) * 130
        height: (parent.parent.width / 2048) * 200
        rotation: -15
        anchors.verticalCenterOffset: -cardList.width/3.8+50
        anchors.horizontalCenterOffset: (parent.parent.width / 2048) *250
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        couleur: "r"
        type: "+2"
        style: "s5"
    }
    Card {
        id: cardOnFront
        x: 894
        y: 377
        width: (parent.parent.width / 2048) * 130
        height: (parent.parent.width / 2048) * 200
        rotation: 15
        anchors.verticalCenterOffset: -cardList.height/4
        anchors.horizontalCenterOffset: (parent.parent.width / 2048) *270
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        couleur: "b"
        type: "8"
        style: "s5"
    }

    Button {
        id: saveBbutton
        x: 864
        y: 516
        width: 250
        height: 70
        Text {
            id: sauvegarder
            color: "white"
            anchors.fill: parent
            text: qsTr("Sauvegarder") + rootItem.emptyString
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.family: "Tahoma"
            font.pixelSize: 20
        }

        onHoveredChanged:
        {
            if(hovered)
                playSnap.play();
        }

        onClicked: {
            playClick.play();
            cardOnBack.style=cardOnFront.style;
            settings.changeCardStyle(cardOnFront.style);
        }

        anchors.verticalCenterOffset: cardList.height/2-height/2
        anchors.horizontalCenterOffset: (parent.parent.width / 2048) *260
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        background:
            Rectangle {
                anchors.fill: parent
                radius: 20
                color: "#272727"
                border.color:  saveBbutton.hovered?"#e98515":"#ffffff"
                border.width: (width / 325) * 15
        }
    }
}
