import QtQuick 2.0
import QtGraphicalEffects 1.0
Item {

    property variant frsource;
    property int  xpos;
    property int  ypos;


    id:live
    width: parent.width
    height: parent.height
    clip:true

    FastBlur{
        id:blur
        source:frsource
        x:-live.x
        y:-live.y
        width: frsource.width
        height: frsource.height
        radius:100
    }

    ColorOverlay{

        anchors.fill: parent
        source: blur
        color: "#40FFFFFF"



    }

}
