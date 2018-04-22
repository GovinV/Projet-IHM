import QtQuick 2.0
import QtQuick.Controls 2.0

Item{
    property var listdata
    property bool show: false

    height: 150
    width: 150*0.65

    Button{
        id: cardbtn
        anchors.fill:parent
        CarteBase{
            color:model.color
            type:model.type
            value: model.value
            showCard:show
        }
/*
        Text{
            id:textindex
            text:index
        }
        Text{
            anchors.top:textindex.bottom
            text: parent.parent.ListView.isCurrentItem ? "selected" : ""
        }
*/
        Rectangle{
            id: cardBorder
            anchors.fill: parent
            radius: 14
            color: "#00000000"
            border.color:  (cardbtn.hovered && show)?"#e98515":"#ffffff"
            border.width: (width / 325) * 24

        }

        background: Rectangle {
            anchors.fill: parent
            color: "#00000000"
        }
        onClicked: {
            listdata.currentIndex = index
            console.log("select");
        }
        onDoubleClicked: {
            game.playCard(index)
        }

    }

}
