/*************************************************************************
**************************************************************************
**************************************************************************
    mac2wepkey by Iktwo - Test the security of your modem.
    Copyright (C) 2012  Iktwo Sh iktwo@ovi.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************
**************************************************************************
**************************************************************************/

#include "wmain.h"

#define WLANCOND_SERVICE "com.nokia.wlancond"
#define WLANCOND_REQ_PATH "/com/nokia/wlancond/request"
#define WLANCOND_REQ_INTERFACE "com.nokia.wlancond.request"
#define WLANCOND_SCAN_REQ "scan"
#define WLANCOND_SIG_PATH "/com/nokia/wlancond/signal"
#define WLANCOND_SIG_INTERFACE "com.nokia.wlancond.signal"
#define WLANCOND_SCAN_RESULTS_SIG "scan_results"

WMain::WMain(QWidget *parent){
    view = new QDeclarativeView(parent);

    rootContext = view->rootContext();
    rootContext->setContextProperty("wMain", this);

    view->setAttribute(Qt::WA_OpaquePaintEvent);
    view->setAttribute(Qt::WA_NoSystemBackground);

    view->setSource(QUrl("qrc:/qml/main.qml"));

    view->showFullScreen();

    QDBusConnection::systemBus().connect(WLANCOND_SERVICE, WLANCOND_SIG_PATH, WLANCOND_SIG_INTERFACE, WLANCOND_SCAN_RESULTS_SIG, this, SLOT(wlanScanResults(QDBusMessage)));
    startScan();

    //int d;
    /*byte seq_20 = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x22, 0x33, 0x11, 0x34, 0x02,(byte)0x81,
    (byte)0xFA,0x22,0x11,0x41,0x68,0x11,0x12,
    0x01,0x05,0x22,0x71,0x42,0x10,0x66
    };*/
}

QString WMain::getHuaweiKey(QString mac){
    int a0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int a1[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int a2[]={0,13,10,7,5,8,15,2,10,7,0,13,15,2,5,8};
    int a3[]={0,1,3,2,7,6,4,5,15,14,12,13,8,9,11,10};
    int a5[]={0,4,8,12,0,4,8,12,0,4,8,12,0,4,8,12};
    int a7[]={0,8,0,8,1,9,1,9,2,10,2,10,3,11,3,11};
    int a8[]={0,5,11,14,6,3,13,8,12,9,7,2,10,15,1,4};
    int a10[]={0,14,13,3,11,5,6,8,6,8,11,5,13,3,0,14};
    int a14[]={0,1,3,2,7,6,4,5,14,15,13,12,9,8,10,11};
    int a15[]={0,1,3,2,6,7,5,4,13,12,14,15,11,10,8,9};
    int n5[]={0,5,1,4,6,3,7,2,12,9,13,8,10,15,11,14};
    int n6[]={0,14,4,10,11,5,15,1,6,8,2,12,13,3,9,7};
    int n7[]={0,9,0,9,5,12,5,12,10,3,10,3,15,6,15,6};
    int n11[]={0,14,13,3,9,7,4,10,6,8,11,5,15,1,2,12};
    int n12[]={0,13,10,7,4,9,14,3,10,7,0,13,14,3,4,9};
    int n13[]={0,1,3,2,6,7,5,4,15,14,12,13,9,8,10,11};
    int n14[]={0,1,3,2,4,5,7,6,12,13,15,14,8,9,11,10};
    int n31[]={0,10,4,14,9,3,13,7,2,8,6,12,11,1,15,5};
    int keys[]={30,31,32,33,34,35,36,37,38,39,61,62,63,64,65,66};

    int DecMAC[12];
    QString key;
    bool ok;

    mac=mac.remove(':');

    for (int var = 0; var < 12; ++var) {
        QString hex = mac.at(var);
        uint dec = hex.toUInt(&ok,16);
        DecMAC[var]=dec;
    }

    key=key+QString::number(keys[(a2[DecMAC[0]])^(n11[DecMAC[1]])^(a7[DecMAC[2]])^(a8[DecMAC[3]])^(a14[DecMAC[4]])^(a5[DecMAC[5]])^(a5[DecMAC[6]])^(a2[DecMAC[7]])^(a0[DecMAC[8]])^(a1[DecMAC[9]])^(a15[DecMAC[10]])^(a0[DecMAC[11]])^13]);
    key=key+QString::number(keys[(n5[DecMAC[0]])^(n12[DecMAC[1]])^(a5[DecMAC[2]])^(a7[DecMAC[3]])^(a2[DecMAC[4]])^(a14[DecMAC[5]])^(a1[DecMAC[6]])^(a5[DecMAC[7]])^(a0[DecMAC[8]])^(a0[DecMAC[9]])^(n31[DecMAC[10]])^(a15[DecMAC[11]])^4]);
    key=key+QString::number(keys[(a3[DecMAC[0]])^(a5[DecMAC[1]])^(a2[DecMAC[2]])^(a10[DecMAC[3]])^(a7[DecMAC[4]])^(a8[DecMAC[5]])^(a14[DecMAC[6]])^(a5[DecMAC[7]])^(a5[DecMAC[8]])^(a2[DecMAC[9]])^(a0[DecMAC[10]])^(a1[DecMAC[11]])^7]);
    key=key+QString::number(keys[(n6[DecMAC[0]])^(n13[DecMAC[1]])^(a8[DecMAC[2]])^(a2[DecMAC[3]])^(a5[DecMAC[4]])^(a7[DecMAC[5]])^(a2[DecMAC[6]])^(a14[DecMAC[7]])^(a1[DecMAC[8]])^(a5[DecMAC[9]])^(a0[DecMAC[10]])^(a0[DecMAC[11]])^14]);
    key=key+QString::number(keys[(n7[DecMAC[0]])^(n14[DecMAC[1]])^(a3[DecMAC[2]])^(a5[DecMAC[3]])^(a2[DecMAC[4]])^(a10[DecMAC[5]])^(a7[DecMAC[6]])^(a8[DecMAC[7]])^(a14[DecMAC[8]])^(a5[DecMAC[9]])^(a5[DecMAC[10]])^(a2[DecMAC[11]])^7]);

    return key;
}

QString WMain::getHuaweiSSID(QString mac){
    int a0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int a1[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int a2[]={0,13,10,7,5,8,15,2,10,7,0,13,15,2,5,8};
    int a3[]={0,1,3,2,7,6,4,5,15,14,12,13,8,9,11,10};
    int a4[]={0,5,11,14,7,2,12,9,15,10,4,1,8,13,3,6};
    int a5[]={0,4,8,12,0,4,8,12,0,4,8,12,0,4,8,12};
    int a6[]={0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8};
    int a8[]={0,5,11,14,6,3,13,8,12,9,7,2,10,15,1,4};
    int a9[]={0,9,2,11,5,12,7,14,10,3,8,1,15,6,13,4};
    int a10[]={0,14,13,3,11,5,6,8,6,8,11,5,13,3,0,14};
    int a11[]={0,12,8,4,1,13,9,5,2,14,10,6,3,15,11,7};
    int a12[]={0,4,9,13,2,6,11,15,4,0,13,9,6,2,15,11};
    int a13[]={0,8,1,9,3,11,2,10,6,14,7,15,5,13,4,12};
    int n1[]={0,14,10,4,8,6,2,12,0,14,10,4,8,6,2,12};
    int n2[]={0,8,0,8,3,11,3,11,6,14,6,14,5,13,5,13};
    int n3[]={0,0,3,3,2,2,1,1,4,4,7,7,6,6,5,5};
    int n4[]={0,11,12,7,15,4,3,8,14,5,2,9,1,10,13,6};
    int n8[]={0,5,11,14,2,7,9,12,12,9,7,2,14,11,5,0};
    int n9[]={0,0,0,0,4,4,4,4,0,0,0,0,4,4,4,4};
    int n10[]={0,8,1,9,3,11,2,10,5,13,4,12,6,14,7,15};
    int n15[]={0,6,12,10,9,15,5,3,2,4,14,8,11,13,7,1};
    int n16[]={0,11,6,13,13,6,11,0,11,0,13,6,6,13,0,11};
    int n17[]={0,12,8,4,1,13,9,5,3,15,11,7,2,14,10,6};
    int n18[]={0,12,9,5,2,14,11,7,5,9,12,0,7,11,14,2};
    int n19[]={0,6,13,11,10,12,7,1,5,3,8,14,15,9,2,4};
    int n20[]={0,9,3,10,7,14,4,13,14,7,13,4,9,0,10,3};
    int n21[]={0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};
    int n22[]={0,1,2,3,5,4,7,6,11,10,9,8,14,15,12,13};
    int n23[]={0,7,15,8,14,9,1,6,12,11,3,4,2,5,13,10};
    int n24[]={0,5,10,15,4,1,14,11,8,13,2,7,12,9,6,3};
    int n25[]={0,11,6,13,13,6,11,0,10,1,12,7,7,12,1,10};
    int n26[]={0,13,10,7,4,9,14,3,8,5,2,15,12,1,6,11};
    int n27[]={0,4,9,13,2,6,11,15,5,1,12,8,7,3,14,10};
    int n28[]={0,14,12,2,8,6,4,10,0,14,12,2,8,6,4,10};
    int n29[]={0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3};
    int n30[]={0,15,14,1,12,3,2,13,8,7,6,9,4,11,10,5};
    int n32[]={0,10,5,15,11,1,14,4,6,12,3,9,13,7,8,2};
    int n33[]={0,4,9,13,3,7,10,14,7,3,14,10,4,0,13,9};
    char ssids[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

    int DecMAC[12];
    QString ssid;
    bool ok;

    mac=mac.remove(':');

    for (int var = 0; var < 12; ++var) {
        QString hex = mac.at(var);
        uint dec = hex.toUInt(&ok,16);
        DecMAC[var]=dec;
    }

    ssid=ssid+ssids[(n1[DecMAC[0]])^(a4[DecMAC[1]])^(a6[DecMAC[2]])^(a1[DecMAC[3]])^(a11[DecMAC[4]])^(n20[DecMAC[5]])^(a10[DecMAC[6]])^(a4[DecMAC[7]])^(a8[DecMAC[8]])^(a2[DecMAC[9]])^(a5[DecMAC[10]])^(a9[DecMAC[11]])^5];
    ssid=ssid+ssids[(n2[DecMAC[0]])^(n8[DecMAC[1]])^(n15[DecMAC[2]])^(n17[DecMAC[3]])^(a12[DecMAC[4]])^(n21[DecMAC[5]])^(n24[DecMAC[6]])^(a9[DecMAC[7]])^(n27[DecMAC[8]])^(n29[DecMAC[9]])^(a11[DecMAC[10]])^(n32[DecMAC[11]])^10];
    ssid=ssid+ssids[(n3[DecMAC[0]])^(n9[DecMAC[1]])^(a5[DecMAC[2]])^(a9[DecMAC[3]])^(n19[DecMAC[4]])^(n22[DecMAC[5]])^(a12[DecMAC[6]])^(n25[DecMAC[7]])^(a11[DecMAC[8]])^(a13[DecMAC[9]])^(n30[DecMAC[10]])^(n33[DecMAC[11]])^11];
    ssid=ssid+ssids[(n4[DecMAC[0]])^(n10[DecMAC[1]])^(n16[DecMAC[2]])^(n18[DecMAC[3]])^(a13[DecMAC[4]])^(n23[DecMAC[5]])^(a1[DecMAC[6]])^(n26[DecMAC[7]])^(n28[DecMAC[8]])^(a3[DecMAC[9]])^(a6[DecMAC[10]])^(a0[DecMAC[11]])^10];

    return ssid;
}

QString WMain::getKey(QString mac){
    /*
      002196 - Telsey (FastWeb-1-002196XXXXXX)
      00036F - Telsey (FastWeb-1-00036FXXXXXX)
      000FE2 - Huawei (INFINITUMXXXX)
      001882 - Huawei (INFINITUMXXXX)
      001E10 - Huawei (INFINITUMXXXX)
      0022A1 - Huawei (INFINITUMXXXX)
      002568 - Huawei (INFINITUMXXXX)
      00259E - Huawei (INFINITUMXXXX)
      00E0FC - Huawei (INFINITUMXXXX)
      286ED4 - Huawei (INFINITUMXXXX)
      6416F0 - Huawei (INFINITUMXXXX)
      781DBA - Huawei (INFINITUMXXXX)
    */
    return "";
}

QString WMain::getTelseyKey(QString mac){

    //lookup3.c, by Bob Jenkins, May 2006, Public Domain.
#define rot(x,k) (((x)<<(k)) | ((x)>>(32-(k))))

#define mix(a,b,c) \
    { \
    a -= c;  a ^= rot(c, 4);  c += b; \
    b -= a;  b ^= rot(a, 6);  a += c; \
    c -= b;  c ^= rot(b, 8);  b += a; \
    a -= c;  a ^= rot(c,16);  c += b; \
    b -= a;  b ^= rot(a,19);  a += c; \
    c -= b;  c ^= rot(b, 4);  b += a; \
}

#define final(a,b,c) \
    { \
    c ^= b; c -= rot(b,14); \
    a ^= c; a -= rot(c,11); \
    b ^= a; b -= rot(a,25); \
    c ^= b; c -= rot(b,16); \
    a ^= c; a -= rot(c,4);  \
    b ^= a; b -= rot(a,14); \
    c ^= b; c -= rot(b,24); \
}

    mac=mac.remove(':');

    uint32_t * keyd;
    uint32_t seed = 0;

    uint32_t  * vector = new uint32_t [64];
    bool status;
    char macValue[6];
    for (int i = 0; i < 12; i += 2)
        macValue[i / 2] = (mac.mid(i,1).toInt(&status, 16) << 4)
                + mac.mid(i + 1,1).toInt(&status, 16);

    vector[0] =( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[1] =( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[2] =( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[3] =( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[4] =( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[5] =( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[5] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[6] =( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[7] =( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[8] =( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[9] =( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[10]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[11]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[12]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[13]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[14]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[15]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[16]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[17]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[18]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[5] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[19]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[20]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[21]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[22]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[23]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[24]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[25]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[26]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[27]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[28]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[29]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[30]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[31]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[32]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[33]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[34]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[35]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[5] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[36]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[37]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[38]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[39]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[40]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[41]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[5] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[42]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[43]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[44]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[45]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[46]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[47]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[48]=( ( ( 0xFF & macValue[1] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[49]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[50]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[51]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[52]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[53]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[5] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[54]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[55]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[0] ) << 8 )|( 0xFF & macValue[4] ) );
    vector[56]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[5] ) );
    vector[57]=( ( ( 0xFF & macValue[4] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[58]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[4] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[0] ) );
    vector[59]=( ( ( 0xFF & macValue[2] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[5] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[60]=( ( ( 0xFF & macValue[3] ) << 24 )|( ( 0xFF & macValue[1] ) << 16 ) |
                 ( ( 0xFF & macValue[2] ) << 8 )|( 0xFF & macValue[3] ) );
    vector[61]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[0] ) << 16 ) |
                 ( ( 0xFF & macValue[1] ) << 8 )|( 0xFF & macValue[2] ) );
    vector[62]=( ( ( 0xFF & macValue[5] ) << 24 )|( ( 0xFF & macValue[3] ) << 16 ) |
                 ( ( 0xFF & macValue[4] ) << 8 )|( 0xFF & macValue[1] ) );
    vector[63]=( ( ( 0xFF & macValue[0] ) << 24 )|( ( 0xFF & macValue[2] ) << 16 ) |
                 ( ( 0xFF & macValue[3] ) << 8 )|( 0xFF & macValue[0] ) );

    keyd = vector;

    for (int x = 0; x < 64; x++) {
        seed = telsey_hashword(keyd,x, seed);
    }

    QString key = "";
    key.setNum(seed,16);

    while ( key.length() < 8 )
        key = "0" + key;

    for ( int x = 0; x <64; x++) {
        if (x <8)
            keyd[x] =( keyd[x]<< 3 ) & 0xFFFFFFFF;
        else if ( x<16)
            keyd[x] >>= 5;
        else if (x < 32 )
            keyd[x] >>= 2;
        else
            keyd[x] =( keyd[x]<< 7 ) & 0xFFFFFFFF;
    }

    seed = 0;
    for (int x = 0; x < 64; x++) {
        seed = telsey_hashword(keyd, x, seed);
    }

    QString key2 =  "";
    key2.setNum(seed,16);
    while ( key2.length() < 8 )
        key2 = "0" + key2;

    return key.right(5) +  key2.left(5);;
}

uint32_t WMain::telsey_hashword(const uint32_t * k,size_t length, uint32_t initval){
    uint32_t a,b,c;

    a = b = c = 0xdeadbeef + (((uint32_t)length)<<2) + initval;

    while (length > 3){
        a += k[0];
        b += k[1];
        c += k[2];
        mix(a,b,c);
        length -= 3;
        k += 3;
    }

    switch(length){
    case 3 : c+=k[2];
    case 2 : b+=k[1];
    case 1 : a+=k[0];
        final(a,b,c);
    case 0:
        break;
    }

    return c;
}

void WMain::startScan(){
    qDebug() << "Scanning..";
    QDBusInterface iface(WLANCOND_SERVICE,
                         WLANCOND_REQ_PATH,
                         WLANCOND_REQ_INTERFACE,
                         QDBusConnection::systemBus());
    QDBusMessage reply = iface.call(WLANCOND_SCAN_REQ, 4, QByteArray("") ,2);
}

void WMain::wlanScanResults(const QDBusMessage &status){
    networksList.clear();

    //The first argument it's the number of networks found
    int total_networks = status.arguments().at(0).toInt();

    for(int i = 0; i < total_networks; ++i){
        int offset = i * 5 + 1;
        QString essid = status.arguments().at(offset++).toString();
        QByteArray bssidBytes = status.arguments().at(offset++).toByteArray();
        offset++;
        uint channel = status.arguments().at(offset++).toInt();

        QString bssid;
        bssid.sprintf("%02X:%02x:%02x:%02x:%02x:%02x",bssidBytes.at(0),bssidBytes.at(1),bssidBytes.at(2),bssidBytes.at(3),bssidBytes.at(4),bssidBytes.at(5));
        QString oui=bssid.mid(0,8);
        QString org = getOrg(oui.toUpper());
        //qDebug() << ">> The org for OUI " << oui << " is " << org;

        addNetwork(essid,bssid.toUpper(),channel,org);
    }
}

QString WMain::getOrg(QString oui){
    QString orgTxt;
    if (oui.simplified().count()>2){
        QFile *file=new QFile("/opt/macoui/data/oui.txt");
        if (file->open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream *t= new QTextStream(file);
            int i=0;
            QString line;
            while ( !t->atEnd() ) {
                i++;
                line=t->readLine();
                if (line.indexOf(oui.replace(":","-"))!=-1){
                    orgTxt=(line.mid(line.indexOf("(hex)")+5).simplified());
                    file->close();
                    delete file;
                    delete t;
                    return orgTxt;
                }else if (i==16104){
                    orgTxt="Org. not found :(";
                    file->close();
                    delete file;
                    delete t;
                    return orgTxt;
                }
            }
            file->close();
            delete t;
        }
        delete file;

    }else{
        return "";
    }
}

void WMain::addNetwork(QString essid, QString bssid, int channel,QString org){
    networksList.append(new NetworkDetails(essid,bssid,channel,org));
    rootContext->setContextProperty("networksModel", QVariant::fromValue(networksList));
}
