import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: mainPage

    tools: commonTools

    /*InfoBanner{
        id: bannerFullPath
        text: actualDir
        timerEnabled: true
        timerShowTime: 3500
        z: 1
        topMargin: 90+10
        //height: 100;
    }*/

    ListView {
        id: listview
        anchors.top: parent.top
        anchors.bottom: btnScan.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        //anchors.fill: parent
        //width: mainPage.width
        clip: true
        model: networksModel
        cacheBuffer: 200;

        delegate: ListDelegate{
            Label {
                id: lblEssid;

                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: 3

                text: essid;
                //font.pixelSize: 28
            }

            Label {
                id: lblBssid;

                anchors.left: lblEssid.right
                anchors.top: parent.top

                text: "-"+bssid;
                //font.pixelSize: 28
            }

            Label {
                id: lblOrg;
                text: org;
                anchors.top: lblEssid.bottom
            }

            Label {
                id: lblChannel;
                text: "Ch "+channel;
                anchors.right: parent.right
                anchors.top: parent.top
            }
        }
    }

    Button{
        id: btnScan;
        text: "Scan"
        height: 50
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onClicked: {
            wMain.startScan();
        }
    }

    ScrollDecorator {
        flickableItem: listview
    }
}
