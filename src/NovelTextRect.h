// Copyright © Matt Jones and Contributors. Licensed under the MIT License (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_NOVELTEXTRECT_H
#define NOVELRT_NOVELTEXTRECT_H
#include "NovelRenderObject.h"
#include "RGBAConfig.h"
#include <string>
#include "GraphicsCharacterRenderData.h"
#include "NovelImageRect.h"
#include "NovelLoggingService.h"

namespace NovelRT {
  class NovelTextRect : public NovelRenderObject {

  private:
    RGBAConfig _colourConfig;
    std::string _fontFileDir;
    std::string _previousFontFileDir = "";
    float _fontSize;
    std::map<GLchar, GraphicsCharacterRenderData> _fontCharacters;
    std::string _text = "";
    std::vector<NovelImageRect*> _letterRects;
    NovelCommonArgs _args;
    NovelLoggingService _logger;

    void reloadText();

  protected:
    void configureObjectBuffers() final;

  public:
    NovelTextRect(NovelLayeringService* layeringService,
                  float fontSize,
                  float screenScale,
                  const std::string& fontFileDir,
                  const RGBAConfig& colourConfig,
                  const NovelCommonArgs& args,
                  GLuint programId);

    RGBAConfig getColourConfig() const;
    void setColourConfig(const RGBAConfig& value);

    std::string getText() const;
    void setText(const std::string& value);

    void drawObject() final;
  };
}
#endif //NOVELRT_NOVELTEXTRECT_H
