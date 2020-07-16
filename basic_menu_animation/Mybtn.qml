import QtQuick 2.0

Rectangle{
    id:myrect
    color: "red"
    property string textStr: "give me some text"
    Text {
        id: btn_text
        anchors.centerIn: parent
        text:myrect.textStr
        color:"white"
        font.pixelSize: 14
    }
    signal bastin()
    signal basili()
    signal birakildi()
    property alias getMauseArea:ma
    MouseArea{
        id:ma
        anchors.fill: parent
        onPressed: {
            //btn_text.text="show menu";
            myrect.basili()

        }
        onReleased: {
            //btn_text.text="press me again";
            myrect.birakildi()
            myrect.bastin()
        }
    }


}

