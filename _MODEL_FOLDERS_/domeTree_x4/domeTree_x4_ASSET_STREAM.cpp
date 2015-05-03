#ifdef WIN32 
void load_domeTree_x4_FromHDtoSystemRAM(void*) 
{                                                           
    fifmt_domeTree_x4 = FreeImage_GetFileType(domeTree_x4_FilePath, 0);       
    dib_domeTree_x4   = FreeImage_Load(fifmt_domeTree_x4, domeTree_x4_FilePath, 0);    
    temp_domeTree_x4  = dib_domeTree_x4;                                      
    dib_domeTree_x4   = FreeImage_ConvertTo32Bits(temp_domeTree_x4);          
    FreeImage_Unload(temp_domeTree_x4);                            

    if( dib_domeTree_x4 != NULL )                                    
    {                                                       
        pixels_domeTree_x4 = (BYTE*)FreeImage_GetBits(dib_domeTree_x4);       
    }                                                     

    domeTree_x4_isLoadedFromDriveAndWaiting = true;                  
    _endthread();                                           
}                                                           
//==========================================================
void delete_domeTree_x4_FromSystemRAM(void)                          
{                                                           
    if( dib_domeTree_x4 != NULL )                                    
    {                                                       
        free(pixels_domeTree_x4);                                    
        FreeImage_Unload(dib_domeTree_x4);                           
    }                                                     

}                                                           
#endif                                                      
