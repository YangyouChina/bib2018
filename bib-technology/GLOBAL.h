#pragma	once

#define   TEXT_FONT     "΢���ź�"              //�޸�ȫ������(���赥���޸�ǰ����Ӧ�Ĵ�����.cpp���޸�)
#define	  TEXT_BOTTOM   "�ȱ��Ƽ�"              //�޸������ڵײ�����
#define   ACCOUNT       "bibeikeji"             //�޸��û���

#define   INIT_TEMP_CONSTANT        30   //��ʼ�㶨�¶�(��λ:��)
#define   INIT_SPEED_CONSTANT        3   //��ʼ�㶨����(��λ:m/s)
#define   INIT_FREQUENCY_CONSTANT   50   //��ʼ���Ƶ��(��λ:Hz)

//#define   PLC_TX_INTERVAL        500  //��PLC�������ݵļ��ʱ��(��λ:ms)
#define   INVERTER_TX_INTERVAL   500  //���Ƶ���������ݵļ��ʱ��(��λ:ms)

//�����������ֽ�������
#define   DTRZ_TX_LEN      92

//������ָ�
#define   OPEN_REFRIGERATION   0x0301
#define   CLOSE_REFRIGERATION  0x0300
#define	  OPEN_HEATER		   0x0401
#define	  CLOSE_HEATER		   0x0400
#define   TEMPSENSOR_BACKUP    0x0500
#define   TEMPSENSOR_MAIN      0x0600
#define	  CHOOSE_HEATER1	   0x0701
#define	  CHOOSE_HEATER2	   0x0702
#define	  CHOOSE_HEATER12	   0x0703
#define   CONSTANT_HEATING     0x08
#define   CONSTANT_REFRIGING   0x09
#define   CALIBRATE_HEATER1    0xf100
#define   CALIBRATE_HEATER2    0xf101
#define   CRC_ERROR			   0xF000

//��Ƶ��ָ�
#define   INVERTER_RUN_COMMAMD          0xFA
#define   INVERTER_RUN_DATA_START       0x02     //��Ƶ������
#define   INVERTER_RUN_DATA_STOP        0x00     //��Ƶ��ֹͣ
#define   INVERTER_SET_FREQ_COMMAND     0xED
#define   INVERTER_RESET_CAMMAND        0xFD
#define   INVERTER_RESET_DATA           0x9696

#define   INVERTER_ENQ     0x05
#define   INVERTER_UNIT    0x01          //��Ƶ��վ��

//PLC��ַ
#define   ADDRESSD_SPEED_SETTING       10
#define   ADDRESSD_SPEED_FEEDBACK      11
#define   ADDRESSD_FREQUENCY           12
#define   ADDRESSD_FREQUENCY_SETTING   13

#define   ADDRESSM_START            20
#define   ADDRESSM_STATE_FAULT      21
#define   ADDRESSM_START_RUNNING    22
#define   ADDRESSM_MODE             23

//�������ģʽ
#define   MODE_AUTO            1
#define   MODE_MANU            2
#define   MODE_MANU_SPEED      3
#define   MODE_MANU_FREQUENCE  4


#define   DTRZMODE_HEATING    1
#define   DTRZMODE_REFRIGING  2



extern CString g_strRecvData;
extern CString g_strTemp;
extern CString g_strSpeed;
extern CString g_strPressure;
extern CString g_strTime;

extern CString g_strPressMS5611[10];
extern CString g_strSpeedHotWire[10];
extern CString g_strSpeedPitot[10];
extern CString g_strPressPitot[10];
extern CString g_strPressDiff[10];
extern CString g_strWindAmtPitot[10];
extern CString g_strTempNew[10];
extern CString g_strRecData[6];

extern BOOL g_bComOpen1;
extern BOOL g_bComOpen2;

extern int g_nCom1;
extern int g_nCom2;

extern DWORD g_TimePauseMs;
extern DWORD g_TimeStartCount;
extern int g_nTimeCount;

extern BOOL g_bTimeCountEnable;

extern CString g_strComNumber1;
extern CString g_strComNumber2;

extern byte bButtonFlag[5];
extern int g_nFlagReadPlcCmd;

extern int g_nTempCon;
extern float g_fSpeedCon;
extern float g_fFrequencyCon;

extern int g_nFlagTemp;
extern int g_nFlagTempCon;
extern int g_nFlagMode;
extern int g_nFlagDTRZMode;

extern int SYS_OK;
extern double g_fSpeedToFrequence[100][2];

WORD CRC16(const BYTE *nData, WORD wLength);
WORD CRC16(CByteArray& nData, WORD wLength);

//������ر�������
extern BOOL g_FlagLineOk;
extern float  g_line_strTemp;
extern float  g_line_strSpeed;
extern float  Speed_minchange;
extern float  Speed_maxchange;
extern float  Temp_minchange;
extern float  Temp_maxchange;
extern int count_time;
extern char BeginTime[100];
//ȫ��ʱ��
extern CString Min;
extern CString Sec;
extern int Time;
extern CSliderCtrl m_Ymin;
extern CSliderCtrl m_Ymax;

extern POINT g_OldSizeTab2;
extern POINT g_OldSizeTab;

extern wchar_t strSavepicpath[_MAX_PATH];
extern wchar_t strSavedatapath[_MAX_PATH];
#define CNWD   1
#define SMin   2
#define SMax   3
#define TMin   4
#define TMax   5

extern int x_gridsize;
extern int y_gridsize;
extern int x_subtract;
extern int   y_subtract;//����Y���򾭹��Ŵ���С��ı����������
extern bool  flag_changeSize;

extern float Speed_Line;//��������