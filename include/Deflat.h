#pragma once
#ifndef __DEFLAT__H__
#define __DEFLAT__H__
#include"..\include\Package.h"
#include"..\include\ComplexMat.h"
#include"..\include\Utils.h"


class InSAR_API Deflat
{
public:
	Deflat();
	~Deflat();
	/*���ǹ�����
	 ����1 �������
	 ����2 ���ϵ��������ֵ��
	*/
	int Orbit_Polyfit(Mat& Orbit, Mat& coef);
	/*��ȡ���������ǳ���λ��ʱ��
	 ����1 ���ǹ�����ķ�λ��ʱ��
	 ����2 ������ϵ��
	 ����3 ���������
	 ����4 ���ǹ����ʼ��λ��ʱ��
	 ����5 ���������ǳ���λ��ʱ�̣�����ֵ��
	*/
	int get_satellite_aztime_NEWTON(double center_time, Mat& coef, Mat pos_xyz, double start_time, double* aztime);
	/*��ȡ������λ��ʱ�̵�����λ��
	 ����1 ������λ��ʱ��
	 ����2 ������ϵ��
	 ����3 ����λ�ã�����ֵ��
	*/
	int get_xyz(double aztime, Mat& coef, Mat& pos_xyz);
	/*��ȡ������λ��ʱ�̵������ٶ�
	����1 ������λ��ʱ��
	����2 ������ϵ��
	����3 �����ٶȣ�����ֵ��
	*/
	int get_vel(double aztime, Mat& coef, Mat& vel_xyz);
	/*��ȡ������λ��ʱ�̵����Ǽ��ٶ�
	����1 ������λ��ʱ��
	����2 ������ϵ��
	����3 ���Ǽ��ٶȣ�����ֵ��
	*/
	int get_acc(double aztime, Mat& coef, Mat& acc_xyz);
	/*ȥƽ�غ���
	 ����1 ��ȥƽ�ظ�����λ
	 ����2 ȥƽ�ظ�����λ
	 ����3 ƽ�ظ�����λ
	 ����4 �����������״���Ƶ�Ȳ�����
	 ����5 ȥƽ�ؿ��Ƶ�
	 ����6 ���ǹ��
	 ����7 ���ǹ��
	 ����8 �շ�ģʽ����������1������˫��2��
	 ����9 ������ӱ�����>= 1��
	*/
	int deflat(	
		Mat& phase,
		Mat& phase_deflat,
		Mat& flat_phase,
		Mat auxi,
		Mat gcps,
		Mat orbit_main,
		Mat orbit_slave,
		int mode,
		int multilook_times
	);
	/** @brief ȥƽ��
	
	@param stateVec1         �������1�����ǹ����δ��ֵ��
	@param stateVec2         �������2�����ǹ����δ��ֵ��
	@param lon_coef          ����ת��ϵ������ͼ������-->���ȣ�
	@param lat_coef          ����ת��ϵ������ͼ������-->γ�ȣ�
	@param phase             ������λ
	@param offset_row        ��ͼ�����Ͻ���ԭʼͼ���е���ƫ����
	@param offset_col        ��ͼ�����Ͻ���ԭʼͼ���е���ƫ����
	@param height            ƽ�ظ߶�
	@param time_interval1    ���1��ֵʱ������1/prf��
	@param time_interval2    ���2��ֵʱ������1/prf��
	@param mode              �շ���ʽ(1���Է����գ�2������˫��)
	@param wavelength        ����
	@param phase_deflated    ȥƽ����λ������ֵ��
	@param flat_phase_coef   ƽ����λ���ϵ��������ֵ��
	*/
	int deflat(
		const Mat& stateVec1,
		const Mat& stateVec2,
		const Mat& lon_coef,
		const Mat& lat_coef,
		const Mat& phase,
		int offset_row,
		int offset_col,
		double height,
		double time_interval1,
		double time_interval2,
		int mode,
		double wavelength,
		Mat& phase_deflated,
		Mat& flat_phase_coef
	);

	/** @brief �����ⲿDEM����ȥ��������λ

	@param phase                 ������λ
	@param dem                   �ⲿDEM����
	@param dem_range_lon         �ⲿDEM���ȷ�Χ��1��2���󣬵�һ����С���ȣ��ڶ�����󾭶ȣ�
	@param dem_range_lat         �ⲿDEMγ�ȷ�Χ��1��2���󣬵�һ����С���ȣ��ڶ�����󾭶ȣ�
	@param stateVec1             ���ǹ�����ݣ�δ��ֵ��
	@param stateVec2             ���ǹ�����ݣ�δ��ֵ��
	@param lon_coef              ����ת��ϵ������ͼ������-->���ȣ�
	@param lat_coef              ����ת��ϵ������ͼ������-->γ�ȣ�
	@param inc_coef              ���ӽ����ϵ����1��11����
	@param offset_row            ��ͼ�����Ͻ���ԭʼͼ���е���ƫ����
	@param offset_col            ��ͼ�����Ͻ���ԭʼͼ���е���ƫ����
	@param interp_interval1      ���ǹ����ֵʱ������1/prf��
	@param interp_interval2      ���ǹ����ֵʱ������1/prf��
	@param mode                  �շ���ʽ(1���Է����գ�2������˫��)
	@param wavelength            ����
	@param B_effect              ��ֱ����
	@param phase_detopo          ȥ������λ�����ֵ��
	*/
	int topo_removal(
		const Mat& phase,
		const Mat& dem,
		const Mat& dem_range_lon,
		const Mat& dem_range_lat,
		const Mat& stateVec1,
		const Mat& stateVec2,
		const Mat& lon_coef,
		const Mat& lat_coef,
		const Mat& inc_coef,
		int offset_row,
		int offset_col,
		double interp_interval1,
		double interp_interval2,
		int mode,
		double wavelength,
		double B_effect,
		Mat& phase_detopo
	);
	/*@brief ����SRTM�߳����ݺ����ǹ������ģ�������λ
	* @param topography_phase                       ������λ������ֵ��
	* @param statevector1                           ���ǹ��
	* @param statevector2                           ���ǹ��
	* @param lon_cofficient                         ����ת��ϵ������ͼ������-->���ȣ�
	* @param lat_cofficient                         ����ת��ϵ������ͼ������-->γ�ȣ�
	* @param inc_cofficient                         ����ת��ϵ������ͼ������-->���ӽǣ�
	* @param prf1                                   ����prf
	* @param prf2                                   ����prf
	* @param sceneHeight                            ��ͼ����
	* @param sceneWidth                             ��ͼ����
	* @param offset_row                             ��ͼ��ԭͼ���е���ƫ��
	* @param offset_col                             ��ͼ��ԭͼ���е���ƫ��
	* @param nearRangeTime                          ��ͼ���б��ʱ�䣨s��
	* @param rangeSpacing                           ��ͼб������������m��
	* @param wavelength                             ����
	* @param acquisition_start_time                 ��ͼԭͼ��λ�������ʼʱ��
	* @param acquisition_stop_time                  ��ͼԭͼ��λ���������ʱ��
	* @param DEMpath                                ���ص�SRTM�߳��ļ�����·��
	* @param interp_times                           SRTM�̲߳�ֵ������Ĭ��Ϊ20��
	* @return �ɹ�����0�����򷵻�-1
	*/
	int topography_simulation(
		Mat& topography_phase,
		Mat& statevector1,
		Mat& statevector2,
		Mat& lon_cofficient,
		Mat& lat_cofficient,
		Mat& inc_cofficient,
		double prf1, double prf2,
		int sceneHeight, int sceneWidth,
		int offset_row, int offset_col,
		double nearRangeTime, double rangeSpacing, double wavelength,
		double acquisition_start_time, double acquisition_stop_time,
		const char* DEMpath,
		int interp_times = 20
	);
	/*@brief ��WGS84����DEMͶӰ����Ӧ��SAR����ϵ��
	* @param DEM84                        84����ϵDEM��short�;���
	* @param mappedDEM                    ͶӰDEM������ֵ,short�;���
	* @param lon_upperleft                84����ϵDEM���ϽǾ���
	* @param lat_upperleft                84����ϵDEM���Ͻ�γ��
	* @param offset_row                   SARͼ����ԭ�����е���ƫ����
	* @param offset_col                   SARͼ����ԭ�����е���ƫ����
	* @param sceneHeight                  SARͼ�񳡾��߶�
	* @param sceneWidth                   SARͼ�񳡾����
	* @param prf                          SAR�����״������ظ�Ƶ��
	* @param rangeSpacing                 ��������������m��
	* @param wavelength                   ����
	* @param nearRangeTime                ���б��ʱ��
	* @param acquisitionStartTime         ��λ�������ʼʱ��
	* @param acquisitionStopTime          ��λ���������ʱ��
	* @param stateVector                  ���ǹ�����ݣ�δ��ֵ��
	* @param interp_times                 84����ϵDEM��ֵ������Ĭ��ֵΪ10��
	* @param lon_spacing                  84����ϵDEM���Ȳ���������㣩
	* @param lat_spacing                  84����ϵDEMγ�Ȳ���������㣩
	* @return �ɹ�����0�����򷵻�-1
	*/
	int demMapping(
		Mat& DEM84,
		Mat& mappedDEM,
		double lon_upperleft,
		double lat_upperleft,
		int offset_row,
		int offset_col,
		int sceneHeight,
		int sceneWidth,
		double prf,
		double rangeSpacing,
		double wavelength,
		double nearRangeTime,
		double acquisitionStartTime,
		double acquisitionStopTime,
		Mat& stateVector,
		int interp_times = 10,
		double lon_spacing = 5.0 / 6000.0,
		double lat_spacing = 5.0 / 6000.0
	);
	/*@brief ��WGS84����DEMͶӰ����Ӧ��SAR����ϵ�У�ͶӰ��γ��Ҳ���أ�
	* @param DEM84                        84����ϵDEM��short�;���
	* @param mappedDEM                    ͶӰDEM������ֵ,short�;���
	* @param mappedLat                    ͶӰγ�����귵��ֵ��double�;���
	* @param mappedLon                    ͶӰ�������꣨����ֵ��double�;���
	* @param lon_upperleft                84����ϵDEM���ϽǾ���
	* @param lat_upperleft                84����ϵDEM���Ͻ�γ��
	* @param offset_row                   SARͼ����ԭ�����е���ƫ����
	* @param offset_col                   SARͼ����ԭ�����е���ƫ����
	* @param sceneHeight                  SARͼ�񳡾��߶�
	* @param sceneWidth                   SARͼ�񳡾����
	* @param prf                          SAR�����״������ظ�Ƶ��
	* @param rangeSpacing                 ��������������m��
	* @param wavelength                   ����
	* @param nearRangeTime                ���б��ʱ��
	* @param acquisitionStartTime         ��λ�������ʼʱ��
	* @param acquisitionStopTime          ��λ���������ʱ��
	* @param stateVector                  ���ǹ�����ݣ�δ��ֵ��
	* @param interp_times                 84����ϵDEM��ֵ������Ĭ��ֵΪ10��
	* @param lon_spacing                  84����ϵDEM���Ȳ���������㣩
	* @param lat_spacing                  84����ϵDEMγ�Ȳ���������㣩
	* @return �ɹ�����0�����򷵻�-1
	*/
	int demMapping(
		Mat& DEM84,
		Mat& mappedDEM,
		Mat& mappedLat,
		Mat& mappedLon,
		double lon_upperleft,
		double lat_upperleft,
		int offset_row,
		int offset_col,
		int sceneHeight,
		int sceneWidth,
		double prf,
		double rangeSpacing,
		double wavelength,
		double nearRangeTime,
		double acquisitionStartTime,
		double acquisitionStopTime,
		Mat& stateVector,
		int interp_times = 10,
		double lon_spacing = 5.0 / 6000.0,
		double lat_spacing = 5.0 / 6000.0
	);
	/*@brief ȥ����׼SLCͼ���еĲο�������λ������ƽ����λ��
	* @param slc_deramped                           ȥ�ο���λ��SLCͼ�񣨷���ֵ��
	* @param mappedDEM                              ��׼��ͼ������ϵDEM
	* @param mappedLat                              DEMγ������
	* @param mappedLon                              DEM��������
	* @param slcH5File                              ��׼SLCͼ��h5�ļ�
	* @param mode                                   �շ�ģʽ��1���Է����գ�2��һ�����գ�Ĭ��Ϊ�Է����գ�
	* @return �ɹ�����0�����򷵻�-1
	*/
	int SLC_deramp(
		ComplexMat& slc,
		Mat& mappedDEM,
		Mat& mappedLat,
		Mat& mappedLon,
		const char* slcH5File,
		int mode = 1
	);
	/*@brief ����ο�б������ǹ��
	* @param slant_range                            �ο�б�ࣨ����ֵ��
	* @param sate_pos                               ����λ�ã�����ֵ��
	* @param sate_vel                               �����ٶȣ�����ֵ��
	* @param mappedDEM                              ��׼��ͼ������ϵDEM
	* @param mappedLat                              DEMγ������
	* @param mappedLon                              DEM��������
	* @param slcH5File                              ��׼SLCͼ��h5�ļ�
	* @return �ɹ�����0�����򷵻�-1
	*/
	int slantrange_compute(
		Mat& slant_range,
		Mat& sate_pos,
		Mat& sate_vel,
		Mat& mappedDEM,
		Mat& mappedLat,
		Mat& mappedLon,
		const char* slcH5File
	);
	/*@brief ȥ����׼SARͼ�����ݶ�ջ�Ĳο�������λ������ƽ����λ��
	* @param SLCH5Files                             ��׼SARͼ�����ݶ�ջh5�ļ�
	* @param reference                              �ο���ͼ�����
	* @param demPath                                DEM���ر���·��
	* @param outSLCH5Files                          ȥ�ο���λ��SARͼ�����ݶ�ջh5�ļ�
	* @return �ɹ�����0�����򷵻�-1
	*/
	int SLCs_deramp(
		vector<string>& SLCH5Files,
		int reference,
		const char* demPath,
		vector<string>& outSLCH5Files
	);
	/*@brief ����ͶӰ��SAR����ϵ��DEM������ϵͳ����ģ�������λ
	* @param mappedDEM                              ͶӰ��SAR����ϵ��DEM��short�ͣ�
	* @param topography_phase                       ������λ������ֵ��
	* @param inc_coefficient                        ���ӽ����ϵ��
	* @param B_effect                               ��ֱ���߳���
	* @param nearRangeTime                          ���б��ʱ��
	* @param offset_row                             SARͼ����ԭSARͼ���е���ƫ����
	* @param offset_col                             SARͼ����ԭSARͼ���е���ƫ����
	* @param wavelength                             ����
	* @param rangeSpacing                           ������������
	* @return �ɹ�����0�����򷵻�-1
	*/
	int topography_phase_simulation(
		Mat& mappedDEM,
		Mat& topography_phase,
		Mat& inc_coefficient,
		double B_effect,
		double nearRangeTime,
		int offset_row,
		int offset_col,
		double wavelength,
		double rangeSpacing
	);
	/*@brief ��������DEM�ĵ���߽�
	* @param lat_coefficient                        ��������ת��ϵ��������-->γ�ȣ�
	* @param lon_coefficient                        ��������ת��ϵ��������-->���ȣ�
	* @param sceneHeight                            �����߶�
	* @param sceneWidth                             �������
	* @param offset_row                             ������ԭͼ���е���ƫ����
	* @param offset_col                             ������ԭͼ���е���ƫ����
	* @param lonMax                                 ��󾭶ȣ�����ֵ��
	* @param latMax                                 ���γ�ȣ�����ֵ��
	* @param lonMin                                 ��С���ȣ�����ֵ��
	* @param latMin                                 ��Сγ�ȣ�����ֵ��
	* @return �ɹ�����0�����򷵻�-1
	*/
	int computeImageGeoBoundry(
		Mat& lat_coefficient,
		Mat& lon_coefficient,
		int sceneHeight,
		int sceneWidth,
		int offset_row,
		int offset_col,
		double* lonMax,
		double* latMax,
		double* lonMin,
		double* latMin
	);
	/*@brief ���ݵ���߽���Ϣ�����������ص�SRTM�߳��ļ���
	* @param lonMin                       ��С����
	* @param lonMax                       ��󾭶�
	* @param latMin                       ��Сγ��
	* @param latMax                       ���γ��
	* @param name                         �ļ���
	* @return �ɹ�����0�����򷵻�-1
	*/
	static int getSRTMFileName(
		double lonMin,
		double lonMax,
		double latMin,
		double latMax,
		vector<string>& name
	);
	/*@brief ���ݵ���߽���Ϣ��ȡSRTM�߳�
	* @param filepath                     ���ص�SRTM�߳��ļ�����·��
	* @param DEM_out                      DEM���ݣ�����ֵ��short�ͣ�
	* @param lonUpperLeft                 ���ϽǾ��ȣ�����ֵ��
	* @param latUpperLeft                 ���Ͻ�γ�ȣ�����ֵ��
	* @param lonMin                       ��С����
	* @param lonMax                       ��󾭶�
	* @param latMin                       ��Сγ��
	* @param latMax                       ���γ��
	* @return �ɹ�����0�����򷵻�-1
	*/
	int getSRTMDEM(
		const char* filepath,
		Mat& DEM_out,
		double* lonUpperLeft,
		double* latUpperLeft,
		double lonMin,
		double lonMax,
		double latMin,
		double latMax
	);
	/*@brief ����SRTM�߳�����
	* @param name                         �ļ���
	* @return �ɹ�����0�����򷵻�-1
	*/
	int downloadSRTM(const char* name);

private:
	char error_head[256];
	char parallel_error_head[256];
	/*DEM���ݣ��߳�Ϊshort�����ݣ�*/
	Mat rawDEM;
	/*DEM��������*/
	int rows;
	/*DEM��������*/
	int cols;
	///*���ϽǾ���*/
	//double lonUpperLeft;
	///*���Ͻ�γ��*/
	//double latUpperLeft;
	///*���½Ǿ���*/
	//double lonLowerRight;
	///*���½�γ��*/
	//double latLowerRight;
	/*DEM�ļ�����·��*/
	string DEMPath;
	/*γ�Ȳ��������Ĭ��Ϊ5.0/6000.0��*/
	double latSpacing;
	/*���Ȳ��������Ĭ��Ϊ5.0/6000.0��*/
	double lonSpacing;
	/*SRTMȫ��߳�url*/
	string SRTMURL = "http://srtm.csi.cgiar.org/wp-content/uploads/files/srtm_5x5/TIFF/";
};


#endif // !__DEFLAT__H__
