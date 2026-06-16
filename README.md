# Spiral Hand 项目网站

这是 Spiral Hand 项目的 GitHub Pages 网站源码。当前版本是一个 Vite + React 静态网站，用来展示 Spiral Hand 总项目以及其中的子项目，例如 PDS Joint 工作。

## 本地运行

```bash
npm install
npm run dev
npm run build
```

- `npm run dev`：启动本地预览页面。
- `npm run build`：执行 TypeScript 检查并生成静态构建文件到 `dist/`。

## 最常改的内容在哪里

大部分文字、链接、图片路径都集中在 `src/content/` 目录，后续优先改这里。

### 1. 首页和全站信息

编辑文件：`src/content/site.ts`

这个文件控制首页和全站级信息：

- 网站/项目名称：`siteInfo.name`
- 首页副标题：`siteInfo.subtitle`
- 首页项目介绍正文：`siteInfo.description`
- 首页右侧 Get Started 卡片标题：`siteInfo.noteTitle`
- 首页右侧 Get Started 列表：`siteInfo.note`（字符串数组，每一项会显示成一行）
- About Us 页面标题：`aboutInfo.title`
- About Us 页面简介：`aboutInfo.intro`
- 单位/实验室信息：`aboutInfo.affiliation`
- 团队成员姓名和邮箱：`aboutInfo.members`
- 首页子项目卡片列表：`siteProjects`

`siteProjects` 中每个对象对应首页的一个子项目卡片，目前只有 PDS Joint。字段含义：

- `title`：卡片标题
- `subtitle`：卡片副标题
- `description`：卡片正文介绍
- `status`：卡片左上角状态标签，例如 `IROS 2026`
- `href`：点击卡片标题进入的页面路由
- `image`：首页卡片左侧图片路径
- `links`：卡片底部链接按钮，例如 Project page / Paper / Video / Code

如果以后要增加新的 Spiral Hand 子项目，在 `siteProjects` 数组里再加一个对象即可。

### 2. PDS Joint 页面内容

编辑文件：`src/content/pdsJoint.ts`

这个文件控制 PDS Joint 项目页的主要内容：

- 论文完整标题：`pdsJoint.title`
- 页面顶部两行大标题：`pdsJoint.titleLines`
- 会议/年份标签：`pdsJoint.venue`
- 作者列表：`pdsJoint.authors`
- 顶部简短介绍：`pdsJoint.summary`
- 摘要：`pdsJoint.abstract`
- 关键词：`pdsJoint.keywords`
- 顶部按钮：`pdsJoint.links`
- 图片路径集合：`pdsJoint.figures`
- 视频路径：`pdsJoint.video`
- Paper contents 四个说明卡片：`pdsJoint.sections`
- Figures 图集卡片：`pdsJoint.media`
- BibTeX：`pdsJoint.citation`

### 3. 导航栏

文件：`src/components/Navigation.tsx`

导航栏目前包含：

- Home
- Projects
- Contact
- About Us 按钮

About Us 按钮会跳转到 `#/about`。About Us 页面内容来自 `src/content/site.ts` 里的 `aboutInfo`。

### 4. 页脚版权文字

页脚目前在两个页面里各写了一次：

- 首页：`src/pages/Home.tsx`
- PDS Joint 页面：`src/pages/PdsJoint.tsx`
- About Us 页面：`src/pages/About.tsx`

当前文字是：

```text
© 2026 Spiral Hand. All rights reserved.
```

如果要换年份、组织名或版权说明，在这两个文件里搜索这句话即可。

## 图片、视频、PDF 放在哪里

所有公开资源都放在：`public/assets/pds/`

### PDF 和视频

- 论文 PDF：`public/assets/pds/paper.pdf`
- 项目视频：`public/assets/pds/intro-video.mp4`

如果只是替换文件，建议保持同名，这样不用改代码。

如果要改文件名，需要同步修改：

- PDF 链接：`src/content/pdsJoint.ts` 里的 `pdsJoint.links`
- 视频路径：`src/content/pdsJoint.ts` 里的 `pdsJoint.video`
- 首页项目卡片里的 Paper / Video 链接：`src/content/site.ts` 里的 `siteProjects[...].links`

### PDS 图片文件

当前图片文件为：

- `public/assets/pds/figures/hero.png`
- `public/assets/pds/figures/design-overview.png`
- `public/assets/pds/figures/spiral-template.png`
- `public/assets/pds/figures/sensing.png`
- `public/assets/pds/figures/results-stiffness.png`
- `public/assets/pds/figures/results-calibration.png`
- `public/assets/pds/figures/grasping-demo.png`
- `public/assets/pds/figures/interaction-demo.png`

最简单的换图方式：用新图片覆盖同名文件。

如果要改文件名，需要同步修改 `src/content/pdsJoint.ts` 里的：

- `pdsJoint.figures`
- `pdsJoint.media`

首页项目卡片图在 `src/content/site.ts` 的 `siteProjects[0].image`，目前也使用 `hero.png`。

## 各个图片/媒体区域的比例

### 1. 首页子项目卡片图

- 页面位置：首页 Projects 区域的子项目卡片左侧
- 内容来源：`src/content/site.ts` 中 `siteProjects[].image`
- CSS 类名：`.project-card-image`
- 推荐图片比例：`4:3` 或略宽
- 显示方式：`object-fit: contain`
- 说明：图片不会裁切，会完整显示；如果图片太宽或太高，周围会留白。

### 2. PDS 顶部右下角背景总览图

- 页面位置：PDS Joint 页面顶部 header 的右下角背景图
- 内容来源：`src/content/pdsJoint.ts` 中 `pdsJoint.figures.overview`
- 当前文件：`public/assets/pds/figures/hero.png`
- CSS 类名：`.paper-header-figure`
- 推荐图片比例：`4:3`
- 显示方式：`object-fit: contain`
- 特殊效果：无硬边框；使用 radial mask 做边缘渐隐，并用 `mix-blend-mode: multiply` 融入背景
- 注意：图片边缘会被柔化，不要把重要文字或关键信息放在图片边缘。

### 3. PDS 视频区域

- 页面位置：PDS Joint 页面 Video 区域
- 视频来源：`src/content/pdsJoint.ts` 中 `pdsJoint.video`
- 当前文件：`public/assets/pds/intro-video.mp4`
- CSS 类名：`.wide-video video`
- 显示比例：`16:9`
- 推荐视频比例：`16:9`

#### 视频封面在哪里改

视频封面目前是单独指定的图片：

```tsx
poster="/assets/pds/figures/video-cover.png"
```

也就是说，视频封面文件应该放在：

```text
public/assets/pds/figures/video-cover.png
```

如果你想换视频封面，直接替换这个文件即可。

如果你想让视频封面改用 PDS 顶部右下角背景总览图，可以修改 `src/pages/PdsJoint.tsx` 中 Video 区域的 `<video>`：

```tsx
<video src={pdsJoint.video} controls playsInline preload="metadata" poster="/assets/pds/figures/video-cover.png" />
```

把 `poster="/assets/pds/figures/video-cover.png"` 改成：

```tsx
poster={pdsJoint.figures.overview}
```

### 4. PDS Figures 轮播区

- 页面位置：PDS Joint 页面 Figures 区域
- 内容来源：`src/content/pdsJoint.ts` 中 `pdsJoint.media`
- 组件文件：`src/components/FigureCarousel.tsx`
- CSS 类名：`.figure-carousel`、`.carousel-media-frame`
- 桌面端显示比例：`4:3`
- 小屏幕显示比例：`4:3`
- 推荐图片比例：`4:3`
- 显示方式：默认 `object-fit: contain`
- 说明：轮播外框占用页面宽度，但图片显示框最大宽度约为 `860px` 并居中；可以点击左右按钮或底部圆点切换；图片不会裁切，过宽或过高时会在框内留白。

每张轮播图的文字在 `pdsJoint.media` 对应项目里改：

- `title`：轮播图标题
- `description`：轮播图说明
- `src`：图片路径
- `fit`：图片填充方式，目前多为 `contain`

如果希望某一张图铺满并裁切，可以把该项的 `fit` 改成：

```ts
fit: 'cover'
```

## 页面结构文件

通常不需要改这些文件，除非你要调整布局结构：

- 首页布局：`src/pages/Home.tsx`
- PDS Joint 页面布局：`src/pages/PdsJoint.tsx`
- About Us 页面布局：`src/pages/About.tsx`
- 顶部导航：`src/components/Navigation.tsx`
- 轮播图组件：`src/components/FigureCarousel.tsx`
- 图片卡片组件：`src/components/MediaCard.tsx`（当前保留备用）
- 链接按钮组件：`src/components/LinkButton.tsx`
- BibTeX 复制区块：`src/components/CitationBlock.tsx`

## 样式文件

- 主布局和组件样式：`src/styles/global.css`
- Memphis 风格装饰图形：`src/styles/memphis.css`

常见可调项：

- 导航栏字体、间距：`global.css` 中 `.site-nav`、`.site-nav nav`、`.site-nav nav a`
- PDS 顶部标题字号：`global.css` 中 `.paper-header h1`
- PDS 顶部背景图大小和位置：`global.css` 中 `.paper-header-figure`
- Figures 轮播图比例、按钮和说明区：`global.css` 中 `.figure-carousel`、`.carousel-media-frame`、`.carousel-arrow`
- About Us 页面介绍和成员卡片：`global.css` 中 `.about-hero`、`.team-grid`、`.team-card`
- Paper contents 卡片颜色：`global.css` 中 `.research-section-card:nth-child(...)`

## 构建输出和不要手动改的文件

- `node_modules/`：依赖目录，由 `npm install` 生成
- `dist/`：构建输出目录，由 `npm run build` 生成
- `package-lock.json`：依赖锁定文件，由 npm 管理

不要手动编辑 `dist/` 里的文件，因为下次 `npm run build` 会重新生成并覆盖它们。

## GitHub Pages 部署说明

这个仓库计划作为组织主页仓库：`spiralhand.github.io`。

对于 GitHub Pages 组织主页仓库，最终访问地址通常是：

```text
https://spiralhand.github.io/
```

当前项目使用 Vite，构建输出目录是 `dist/`。仓库中已经包含 GitHub Actions 工作流：

```text
.github/workflows/deploy-pages.yml
```

推送到 `main` 分支后，GitHub Actions 会自动执行：

```bash
npm ci
npm run build
```

然后把 `dist/` 发布到 GitHub Pages。

首次使用时，需要在 GitHub 仓库的 Settings → Pages 中把 Source 设置为 **GitHub Actions**。

## 版权和 License

网页页脚当前使用：

```text
© 2026 Spiral Hand. All rights reserved.
```

目前没有单独添加开源 `LICENSE` 文件。原因是这个仓库现在主要是项目展示网站，不一定代表代码、CAD、数据集或硬件设计已经开放授权。

如果之后要公开代码、CAD 文件、数据集或硬件设计，建议新增明确的 `LICENSE` 文件，并在 README 中说明 license 覆盖哪些内容。