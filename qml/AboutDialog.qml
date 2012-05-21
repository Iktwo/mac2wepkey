import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    id: aboutPage
    orientationLock: PageOrientation.LockPortrait
    anchors { fill: parent; margins: UiConstants.DefaultMargin }
    opacity: .8

    Image {
        id: appIcon
        source: "qrc:/resources/icons/logo.png"
        anchors { top: parent.top; horizontalCenter: parent.horizontalCenter }
    }

    Label {
        id: appInfo
        anchors {
            top: appIcon.bottom
            topMargin: UiConstants.DefaultMargin
            horizontalCenter: parent.horizontalCenter
        }

        text: appName + " Ver " + appVersion
              + "\n(C) 2012 " + appOrg + "\n"
    }

    Column {
        id: buttonsColumn
        spacing: 5
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter }
        visible: (rootWindow.pageStack.depth !== 1) ? true : false

        Button {
            text: "Ok"

            onClicked: {
                pageStack.pop();
            }
        }
    }

    Flickable {
        id: flickText

        clip: true
        contentHeight: helpText.height

        anchors {
            top: appInfo.bottom;
            bottom: buttonsColumn.top
            bottomMargin: UiConstants.DefaultMargin
            left: parent.left
            right: parent.right
        }

        Column {
            id: helpText
            width: aboutPage.width

            Label {
                width: parent.width
                textFormat: Text.RichText
                wrapMode: Text.WordWrap
                text: "This program comes with ABSOLUTELY NO WARRANTY;\n
                       This is free software, and you are welcome to redistribute it\n
                       under certain conditions.\n\n"
            }

            Label {
                width: parent.width
                wrapMode: Text.WordWrap
                onLinkActivated: Qt.openUrlExternally("mailto:iktwo@ovi.com")
                text: "<br>
                        Test the security of several modems, you can scan networks near you.."
                        +
                        "<br><br> If you like my work please support
                        me buying my apps and giving me feedback.
                        <br><br> &copy; Iktwo 2012<br><br>Bugs/Comments
                        <br> Contact me <br><br>
                        Email: <a href=\"mailto:iktwo@ovi.com\">iktwo@ovi.com</a>
                        <br> Twitter: @iktwo"
            }

            Label {
                width: parent.width
                wrapMode: Text.WordWrap
                onLinkActivated: Qt.openUrlExternally("http://iktwo.com")
                text: "<b> http://iktwo.com</b>"
            }
        }
    }
    ScrollDecorator {
        flickableItem: flickText
    }
}
