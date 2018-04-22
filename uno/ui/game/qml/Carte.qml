import QtQuick 2.0
import QtQuick.Controls 2.0

Item{
    property var listdata

    height: 150
    width: 150*0.65

    Rectangle{
        anchors.fill:parent
        CarteBase{
            color:model.color
            type:model.type
            value: model.value
        }

        Text{
            id:textindex
            text:index
        }
        Text{
            anchors.top:textindex.bottom
            text: parent.parent.ListView.isCurrentItem ? "selected" : ""
        }

        color:"transparent"

    }
    MouseArea{

        anchors.fill:parent
        onClicked: {
            listdata.currentIndex = index
            console.log("select");
        }
    }

}
