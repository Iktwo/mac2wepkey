import QtQuick 1.0
import com.nokia.meego 1.0

Column {

        property alias tittle: mainPageTitleText.text;
        property alias author: mainPageAuthorText.text;

        property alias color: mainPageTitle.color;

        property alias logo: image1.source;
        property alias logoWidth: image1.width;

        property alias logoLink: logoLink.text;
        property alias tittleLink: tittleLink.text;
        property alias authorLink: authorLink.text;

        id: mainPageColumn
        width: parent.width
        height: 72

        Component.onCompleted: {
            console.log("mainPageTitleText"+mainPageTitleText.y)
            console.log("mainPageAuthorText"+mainPageAuthorText.y)
        }

        Rectangle {
            id: mainPageTitle
            width: parent.width
            height: 72

            Label {
                id: mainPageTitleText
                anchors.left: parent.left
                anchors.leftMargin: 15
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 35
                color:  "white"
                MouseArea {
                    id: mouse_area_tittle
                    anchors.fill: parent
                    onClicked: Qt.openUrlExternally(tittleLink.text);
                }
            }

            Label {
                id: mainPageAuthorText
                x: mainPageTitle.width-15-mainPageAuthorText.width-image1.width
                anchors.verticalCenter: mainPageTitleText.verticalCenter
                font.pixelSize: 30
                color:  "white"
                MouseArea {
                    id: mouse_area_author
                    anchors.fill: parent
                    onClicked: Qt.openUrlExternally(authorLink.text);
                }
            }

            Text {
                id: logoLink
                opacity: 0
            }

            Text {
                id: authorLink
                opacity: 0
            }

            Text {
                id: tittleLink
                opacity: 0
            }

            Image {
                id: image1
                x: mainPageTitle.width-72
                y: 0
                width: 72
                height: 72

                MouseArea {
                    id: mouse_area_logo
                    anchors.fill: parent
                    onClicked: Qt.openUrlExternally(logoLink.text);
                }
            }

        }

    }
