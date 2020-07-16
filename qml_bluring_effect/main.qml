import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height:680
    title: qsTr("Hello World")

    Rectangle{
        id:rootrect
        anchors.fill: parent
        property int value:0
        Image {
            id: myim
            anchors.fill:parent
            source: "myimage.jpg"
        }
        Text {
            id: roottexrt
            anchors.centerIn: parent
            font.pixelSize: parent.height/3
            color:"white"
            text: rootrect.value
            Component.onCompleted: {
                mytmr.start()
            }
        }

        Timer{
            id:mytmr
            interval: 1000
            repeat: true
            running: false
            onTriggered: {
                parent.value+=10
            }

        }

    }
    LiveBlur{
        id:lvblr
        frsource: rootrect
        xpos:rootrect.value
        ypos:rootrect.value
    }


}
