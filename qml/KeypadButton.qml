import QtQuick 1.0

Rectangle{
    signal pressed
    property alias text: buttonText.text;

    id: symbolContainer
    width: 110
    height: 110
    radius: 38
    color: "#dee3e7"

    Rectangle{
        id: backgroundBtn
        anchors.fill: parent
        width: 110
        height: 110
        radius: 38
        opacity: 0
        color: "#ffffff"
        states: [
            State {
                name: "NORMAL"
                PropertyChanges {
                    target: backgroundBtn;
                    opacity: 0;
                }
            },
            State {
                name: "PRESSED"
                PropertyChanges {
                    target: backgroundBtn;
                    opacity: 0.7;
                }
            }
        ]

        transitions: [
            Transition {
                from: "PRESSED"
                to: "NORMAL"
                PropertyAnimation { properties: "opacity"; easing.type: Easing.InOutQuad; duration: 600}
            },
            Transition {
                from: "NORMAL"
                to: "PRESSED"
                PropertyAnimation { properties: "opacity"; easing.type: Easing.InOutQuad; duration: 200 }
            }
        ]
    }

    Text{
        id: buttonText;
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 45
        font.bold: true
    }

    MouseArea {
        id: mouse_area1
        opacity: 1
        anchors.fill: parent
        onPressed: {
                backgroundBtn.state = "PRESSED"
                symbolContainer.pressed()
        }

        onReleased: {
                backgroundBtn.state = "NORMAL"
        }
    }
}
