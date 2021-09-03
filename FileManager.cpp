#include "FileManager.h"
#include <filesystem>
#include "easylogging++.h"
#include "Util.h"
#define PACK_COUNT 5
std::string PACK_FILE[PACK_COUNT] = {"homestyler-model-agents","homestyler-transform-worker","t3d-cloud-platform","t3d-unify-scheduler","t3d-unify-scheduler" };
std::string PACK_FILE_PATH[PACK_COUNT] = {"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\homestyler-model-agents","D:\\InstallSource\\Pipeline\\bin\\SourceFile\\homestyler-transform-worker",
"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\t3d-cloud-platform" ,"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\t3d-unify-scheduler","D:\\InstallSource\\Pipeline\\bin\\SourceFile"};
struct _file_node {
	std::string file_name;
	std::string file_node_name;
	bool file_node_filter;
	std::string comment;
};

FileManager* Singleton<FileManager>::m_pSingleton = NULL;
FileManager::FileManager()
{

}

FileManager::~FileManager()
{


}

bool FileManager::ConfigueFilter()
{
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\acetiny\\AceTinyModelCaptureHandler.java", "acetiny-model-capture", true, "获取acetiny模型图片打包压缩png");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\converter\\EncoderHandler.java", "encoder", true, "转换成T3D引擎");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\converter\\ModelPackerHandler.java", "model-packer", true, "打包模型");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\AsterMaterialTransformHandler.java", "aster-material-transform", true, "aster材质转换");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\D2nHandler.java", "d2n-handler", true, "转换normal");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\GenerateMaterialUVInfoHandler.java", "gen-aster-material-uvinfo", true, "gen-aster-material-uvinfo？");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\GenNormalHandler.java", "gen-normal", true, "生成法线");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\GenTextureScaleSuggesionHandler.java", "gen-3d-wallfloor-config", true, "t3d产生烘焙的地方");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\LightTransformHandler.java", "light-transform", true, "灯光转换");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\MaterialPicturesConvertHandler.java", "material-pictures-convert", true, "材质转换");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\OverlayTextureHandler.java", "texture-merge", false, "图片合成调用java_Graphics2D提供通道");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\PreConvertTextureByUrlHandler.java", "pre-convert-texture-by-url", true, "图片预处理resize");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\PreConvertTextureHandler.java", "pre-convert-texture", true, "图片预处理compress");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\ResizeTextureHandler.java", "texture-resize", true, "图片resize");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\TextureConvertHandler.java", "texture-convert", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\TextureConvertUnionHandler.java", "texture-convert-union", false, "统一整理texture-convert");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\TextureFilesConvertHandler.java", "texture-files-convert", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\TextureImageConvertHandler.java", "texture-image-convert", true, "用于单张贴图处理链路的贴图转换");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\material\\TrimTextureHandler.java", "texture-cut", true, "贴图trim");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\simplify\\impl\\GenerateShape.java", "generate-shape", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\simplify\\impl\\PublishATX.java", "publish-atx", false, "oss上传");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\simplify\\impl\\ScaleObjHandler.java", "scale-obj", true, "缩放obj");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\simplify\\impl\\SetAtxUniformResource.java", "set-atx-uniform-resource", false, "上传obj");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\simplify\\impl\\SimplifyMeshT3DToolHandler.java", "simplify-mesh", true, "减面");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\simplify\\impl\\SimplifyVrsceneHandler.java", "simplifyVrscene", true, "vray减面");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\skeleton\\T3dAddSkeletonHandler.java", "t3d-add-skeleton", true, "修改t3d模型数据，添加骨骼相关信息");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\skeleton\\VrsceneAddSkeletonHandler.java", "vrscene-add-skeleton", true, "修改vrscene模型数据，添加骨骼相关信息");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\AsterModelStatisticHandler.java", "aster-model-statistic", "fasle", "统计Aster模型中存在transparent");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\CompressZstdHandler.java", "t3d-zstd-compress", false, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\FilterModelHandler.java", "filter-model", false, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\IESModelStatisticHandler.java", "t3d-ies-statistic", false, "统计模型中存在IES的jid列表");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\LightInfoStatisticHandler.java", "t3d-lightinfo-statistic", false, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\ObjInfoToolHandler.java", "obj-info-tool-new", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\StatisticGammaErrorHandler.java", "vray-gammaerror-statistic", false, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\statistic\\StatiticFittingExhibiteUVHandler.java", "statistic-fitting-exhibite-uv", false, "统计跑过拟合任务但是重展了uv的jid列表");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\unifiedpostprocessing\\ColorExtract.java", "unified-color-extract", true, "颜色提取");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\unifiedpostprocessing\\CutIso.java", "unified-texture-cut", true, "贴图trim");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\unifiedpostprocessing\\ResizeIso.java", "unified-texture-resize", true, "resizeiso");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\video\\VideoClipHandler.java", "video-clip", true, "视频裁剪参考开源ffmpeg");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\video\\VideoEncoder.java", "video-encoder", true, "callnvidiaffmpegencoder.");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\myhome\\AceTinyLightProbe2SHMyHome.java", "acetiny-light-probe-to-sh-my-home", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\myhome\\AceTinyLightProbeGroupConfig2TextureMyHome.java", "AceTinyLightProbeGroupConfig2TextureMyHome", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\myhome\\AceTinyMobileScenePostProcessMyHome.java", "acetiny-mobile-scene-post-process-my-home", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\myhome\\AceTinyPanorama2GIMyHome.java", "acetiny-panorama-to-gi-my-home", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\myhome\\MobileSceneCollectMyHomeHandler.java", "ace-mobile-scene-collect-myhome", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\myhome\\MobileSceneCullMyHomeHandler.java", "ace-mobile-scene-culler-myhome", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceGeometry2MobileStuff.java", "acegeometry-2-mobile-stuff", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceGeometryLightmapperHandler.java", "acegeometry-lightmapper", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceGeometryLightmapUVGenHandler.java", "acegeometry-lightmap-uvgen", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceGeometryLightmapUVPackerHandler.java", "acegeometry-lightmap-uvpacker", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceTinyGenMinimapHandler.java", "acetiny-gen-minimap", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceTinyIBLGenHandler.java", "ace-ibl-generator", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceTinyLightProbe2SH.java", "acetiny-light-probe-to-sh", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceTinyMobileScenePostProcess.java", "acetiny-mobile-scene-post-process", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\AceTinyPanoTextureSplit.java", "acetiny-pano-texture-split", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\BackgroundMapPacker.java", "ace-background-map-packer", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\MobileSceneCullHandler.java", "ace-mobile-scene-culler", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrlightmap\\VrScene2AceGeometryHandler.java", "vrscene-2-acegeometry", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\vrscene\\VrSceneTransformHandler.java", "vrscene_transform", "", "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\Aster2VrsceneToolHandler.java", "aster-to-vrscene", true, "astertovrscene");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\AsterBakeToolHandler.java", "acetiny-aster-bake", true, "asterbake");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\AsterMaterialBakeHandler.java", "aster-material-bake", true, "astermaterialbake");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\CaptureToolHandler.java", "fitting-aster-capture", true, "获取iso");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\ClothMeshTransformHandler.java", "cloth-model-transform", true, "布料模型转换");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\ColorExtractHandler.java", "color-extract", false, "颜色提取");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\CompressPBRToolHandler.java", "compress-pbr", true, "压缩模型");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\ConvertPBRShadowHandler.java", "convert-pbr-shadow", false, "PBRshadow转换");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\EvaluateLightmapSizeHandler.java", "EVALUATE_LIGHTMAP_SIZE", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\FittingToolHandler.java", "t3d-material-fitting", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\GenBakedSceneModelHandler.java", "GEN_BAKED_SCENE_MODEL", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\MobileTextureCompressHandler.java", "mobile-texture-compress", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\ModelTransformCommonHandler.java", "ModelTransformCommonHandler", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\PBRInputToolHandler.java", "pbr-input", false, "pbr函数输入");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\PBRMaterialAdjustToolHandler.java", "pbr-material-adjust", true, "vray材质输入");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\PrepackHandler.java", "pre-pack", false, "删除部分文件");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\PreprocessBakingSceneHandler.java", "PREPROCESS_BAKING_SCENE", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\SamplerToolHandler.java", "t3d-material-sampler", true, "t3d采样");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\SceneStructure2ModelHandler.java", "SCENE_STRUCTURE_2_MODEL", true, "renderSDKCmd");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\Shape2SvgHandler.java", "shape2svg", false, "调用python，PNG产生SVG");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3d2AsterToolHandler.java", "t3d-to-aster", true, "t3dtoaster");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3d2PBRToolHandler.java", "t3d-to-pbr", true, "t3dtopbr");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3DLightMeshBVHHandler.java", "t3d-lightmesh-bvh", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dObjBakeToolHandler.java", "t3d-bake-obj", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dOBJCaptureHandler.java", "t3d-obj-capture", true, "JSoftwareRenderer");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dObjOptimizeToolHandler.java", "t3d-optimize-obj", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dPackageTextureResizeHandler.java", "t3d-package-texture-resize", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dPostprocess2DToolHandler.java", "t3d-postprocess-2d", false, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dPostprocessToolHandler.java", "t3d-postprocess", "ture", "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\T3dRemeshToolHandler.java", "t3d-remesh", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\TextureOptimizerHandler.java", "texture-optimizer", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\VRayCaptureToolHandler.java", "vray-capture", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\Vrscene2AlimodelToolHandler.java", "vrscene-to-alimodel", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\VrSceneInfoExtractHandler.java", "vrscene-info-extract", true, "");
	AddFileNode("D:\\GitSource\\t3d-material-fitting\\material-fitting-service\\src\\main\\java\\com\\taobao\\t3d\\fitting\\service\\VrsceneStaticsHandler.java", "vrscene-statistic", true, "");
	return true;
}


bool FileManager::AddFileNode(std::string _name, std::string _node_name, bool filter,std::string comment,std::string pack)
{
	FileNode node;
	node.filePath = _name;
	node.fileName = _node_name;
	node.filePack = pack;
	ReplaceAll(_name, "\\", ".");
	ReplaceAll(_name, "/", ".");
	node.replaceNode = _name;
	node.comment = comment;
	node.execPos.push_back("line 1");
	FileNodePair pairIter = m_mapFileNodes.insert(std::make_pair(_name, node));
	if (!pairIter.second)
	{
		LOG(ERROR) << "FileManager:: filename already exists:" << _node_name << " path:" << _name;
		return false;
	}
	return true;
}

bool FileManager::Init()
{
	ConfigueFilter();
	for (int i = 0; i < PACK_COUNT; ++i)
	{
		TraversePath(PACK_FILE_PATH[i], PACK_FILE[i]);
	}
	return true;
}


void FileManager::ReadFile(std::string filename,std::vector<std::string> & execCmds)
{
    std::string str;
    std::ifstream in(filename);
    char tempData[256] = { 0 };

	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			std::size_t found = str.find("Runtime.getRuntime().exec");
			if (found != std::string::npos)
			{
				std::string execStr = std::string("line:")+ std::to_string(__LINE__) + std::string(" func:") + __func__;
				execCmds.push_back(execStr);
			}
		}
	}
	return;
}

FileNode * FileManager::GetBindFile(std::string &classRef)
{
	FileNodeIter iter = m_mapFileNodes.begin();
	for (; iter != m_mapFileNodes.end(); ++iter)
	{
		std::string::size_type postion  = iter->second.replaceNode.find(classRef);
		if (postion != std::string::npos)
		{
			return &iter->second;
		}
	}
	return NULL;
}

FileNode* FileManager::GetBindNodeFile(std::string node, std::string task_type)
{
	FileNodeIter iter = m_mapFileNodes.begin();
	for (; iter != m_mapFileNodes.end(); ++iter)
	{
		std::string::size_type postion = iter->second.fileName.find(node);
		if (postion != std::string::npos)
		{
			return &iter->second;
		}
	}
	return NULL;
}

FileNode* FileManager::GetBindFileNode(std::string node, std::string task_type)
{
	FileNodeIter iter = m_mapFileNodes.begin();
	for (; iter != m_mapFileNodes.end(); ++iter)
	{
		std::string::size_type postion = iter->second.fileName.find(node);
		if (postion != std::string::npos)
		{
			return &iter->second;
		}
	}
	return NULL;
}


void FileManager::TraversePath(std::string path,std::string pack)
{
	std::vector<std::string> mapFiles;
	const std::filesystem::path rootPath(path);
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ rootPath })
		if (dir_entry.path().extension() == ".java") {

			std::string filePath = dir_entry.path().string();

			std::string fileName = dir_entry.path().filename().replace_extension().string();

			FileNode node;
			node.filePath = filePath;
			node.fileName = fileName;
			node.filePack = pack;
			ReplaceAll(filePath, "\\", ".");
			ReplaceAll(filePath, "/", ".");
			node.replaceNode = filePath;
			ReadFile(filePath, node.execPos);
			mapFiles.push_back(filePath);
			FileNodePair pairIter = m_mapFileNodes.insert(std::make_pair(filePath, node));
			if (!pairIter.second)
			{
				LOG(ERROR) << "FileManager:: filename already exists:" << fileName << " path:" << filePath;
			}
		}
}
