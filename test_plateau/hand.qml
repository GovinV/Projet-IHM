import QtQuick 2.0
import game.handmodel 1.0

ListView {
    model:HandModel{
        objectName: "model"
    }


    delegate: Carte{
        Rectangle{
            color: "red"
            Text{
                text:model.couleur
            }
        }
    }
}
