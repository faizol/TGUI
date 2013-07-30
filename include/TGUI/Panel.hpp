/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012-2013 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_PANEL_HPP
#define TGUI_PANEL_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief A static container of widgets. The background color can be solid or transparent.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Panel : public ContainerWidget
    {
      public:

        typedef SharedWidgetPtr<Panel> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Panel();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Panel(const Panel& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Panel();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Panel& operator= (const Panel& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Panel* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the panel.
        ///
        /// \param width   Sets the new width of the panel
        /// \param height  Sets the new height of the panel
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the panel.
        ///
        /// \return Size of the panel
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the background texture of the panel.
        ///
        /// \param texture  Pointer to the texture that should be used as background of the panel
        ///
        /// \warning You should make sure that the texture stays alive.
        ///
        /// If the texture has a different size than the panel then it will be scaled to fill the whole panel.
        /// Pass nullptr to this function to remove the background texture.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundTexture(sf::Texture *const texture = nullptr);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the background texture of the panel.
        ///
        /// \return Pointer to the texture that is being used as background of the panel.
        ///         This pointer is nullptr when no background texture was set.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::Texture* getBackgroundTexture();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the background color of the panel.
        ///
        /// \param backgroundColor  New background color
        ///
        /// The background is fully transparent by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(const sf::Color& backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the background color of the panel.
        ///
        /// The background is fully transparent by default.
        ///
        /// \return The current background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::Color& getBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the transparency of the widget.
        ///
        /// \param transparency  The transparency of the widget.
        ///                      0 is completely transparent, while 255 (default) means fully opaque.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTransparency(unsigned char transparency);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used to communicate with EventManager.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnWidget(float x, float y);
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void widgetFocused();
        virtual void widgetUnfocused();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are a (slow) way to set properties on the widget, no matter what type it is.
        // You can e.g. change the "Text" property, without even knowing that the widget is a button.
        // When the requested property doesn't exist in the widget then the functions will return false.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool setProperty(const std::string& property, const std::string& value);
        virtual bool getProperty(const std::string& property, std::string& value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the widget on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Defines specific triggers to Panel.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum PanelCallbacks
        {
            LeftMousePressed = WidgetCallbacksCount * 1,      ///< The left mouse button was pressed
            LeftMouseReleased = WidgetCallbacksCount * 2,     ///< The left mouse button was released
            LeftMouseClicked = WidgetCallbacksCount * 4,      ///< The left mouse button was clicked
            AllPanelCallbacks = WidgetCallbacksCount * 8 - 1, ///< All triggers defined in Panel and its base classes
            PanelCallbacksCount = WidgetCallbacksCount * 8
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        Vector2f     m_Size;

        sf::Color    m_BackgroundColor;

        sf::Texture* m_Texture;
        sf::Sprite   m_Sprite;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        friend class Container;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_PANEL_HPP
