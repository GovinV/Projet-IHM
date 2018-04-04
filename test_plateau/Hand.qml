import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Hand 1.0
//Frame {
    ListView{

        property bool cardsFlipped: true

        orientation: ListView.Horizontal

        // ajuster en foncion de la taille de l'ecran et/ou de la taille de la main
        implicitHeight: 100
        implicitWidth: parent.width
        clip: true

        //ajuster la valeur en fonction du nombre de carte
        spacing: -50

        model:HandModel{

        }

        delegate: RowLayout{
            /*Rectangle{
                width: 70
                height: 100
                Image{
                    anchors.fill:parent
                    source: model.sourceImg
                }
            }*/
            Card{
                property bool flipped: cardsFlipped
                front: Image{
                    id: frontImg
                    anchors.fill:parent
                    source: model.sourceImg
                }
            }
        }
    }
//}
