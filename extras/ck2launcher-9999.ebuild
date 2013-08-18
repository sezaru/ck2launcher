# Based on ffmpeg ebuild
# Copyright 2010 Enno Gröper
# Distributed under the terms of the GNU General Public License v2

EAPI=4

inherit cmake-utils git-2

DESCRIPTION="A custom Qt5 launcher for Crusader Kings 2 game."
HOMEPAGE="https://github.com/sezaru/ck2launcher"
SRC_URI=""

EGIT_REPO_URI="https://github.com/sezaru/ck2launcher.git"

LICENSE="GPL-3"
SLOT="0"
KEYWORDS="~amd64 ~x86"

DEPEND="|| ( >=sys-devel/gcc-4.7.2 >=sys-devel/clang-3.3 )
        >=dev-libs/boost-1.50
        dev-qt/qtcore:5
        dev-qt/qtwidgets:5
        dev-qt/qtwebkit:5"
RDEPEND="${DEPEND}"

src_configure()
{
    cmake-utils_src_configure
}

src_install()
{
    cmake-utils_src_install
}
