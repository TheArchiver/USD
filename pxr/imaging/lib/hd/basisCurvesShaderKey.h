//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef HD_BASIS_CURVES_SHADER_KEY_H
#define HD_BASIS_CURVES_SHADER_KEY_H

#include "pxr/imaging/hd/version.h"
#include "pxr/imaging/hd/enums.h"
#include "pxr/imaging/garch/gl.h"
#include "pxr/base/tf/token.h"

struct Hd_BasisCurvesShaderKey
{
    Hd_BasisCurvesShaderKey(TfToken const &basis, bool authoredNormals, 
                            bool refine);
    ~Hd_BasisCurvesShaderKey();

    TfToken const &GetGlslfxFile() const { return glslfx; }
    TfToken const *GetVS() const  { return VS; }
    TfToken const *GetTCS() const { return TCS; }
    TfToken const *GetTES() const { return TES; }
    TfToken const *GetGS() const  { return NULL; }
    TfToken const *GetFS() const  { return FS; }
    bool IsCullingPass() const { return false; }
    GLenum GetPrimitiveMode() const { return primitiveMode; }
    int16_t GetPrimitiveIndexSize() const { return primitiveIndexSize; }
    HdCullStyle GetCullStyle() const { return HdCullStyleDontCare; }
    HdPolygonMode GetPolygonMode() const { return HdPolygonModeFill; }

    GLenum primitiveMode;
    int16_t primitiveIndexSize;
    TfToken glslfx;
    TfToken VS[4];
    TfToken TCS[4];
    TfToken TES[5];
    TfToken FS[6];
};

#endif  // HD_BASIS_CURVES_SHADER_KEY
