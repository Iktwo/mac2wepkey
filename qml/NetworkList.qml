import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: mainPage

    tools: commonTools

    InfoBanner{
        id: infoBanner;
        timerEnabled: true
        timerShowTime: 2500
        z: 1
    }

    ListView {
        id: listview
        anchors.top: parent.top
        anchors.bottom: btnScan.top
        anchors.left: parent.left
        anchors.right: parent.right
        clip: true
        model: networksModel
        contentHeight: networksModelCount * delegate.height

        delegate: ListDelegate{
            id: delegate
            width: parent.width
            height: lblBssid.height + lblOrg.height + 20

            Rectangle{
                anchors.fill: parent
                color: "#000000"

                Label {
                    id: lblEssid;
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.leftMargin: 3
                    text: essid;
                }

                Label {
                    id: lblBssid;
                    anchors.left: lblEssid.right
                    anchors.top: parent.top
                    text: "-"+bssid;
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

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        var key = wMain.getKey(bssid);
                        if (key == "Not found"){
                            infoBanner.text = "Key not found";
                        }else{
                            infoBanner.text = "Key found, " + key +" copied to clipboard";
                        }
                        infoBanner.show();
                    }
                }
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
