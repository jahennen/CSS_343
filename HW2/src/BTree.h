  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>CSS_343/HW2/src/BTree.h at master · jahennen/CSS_343</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon-precomposed" sizes="57x57" href="apple-touch-icon-114.png" />
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="apple-touch-icon-114.png" />
    <link rel="apple-touch-icon-precomposed" sizes="72x72" href="apple-touch-icon-144.png" />
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="apple-touch-icon-144.png" />
    <link rel="logo" type="image/svg" href="http://github-media-downloads.s3.amazonaws.com/github-logo.svg" />
    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="JadKVnVOmD6VSK+zaG6jpeVWZSpcNRaYEmn0R6U5k1w=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/assets/github-99d5aa340769a79940de3574f1847934fb1babe0.css" media="screen" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/assets/github2-9c2d70f63186aa312d782143624a3c94b8739271.css" media="screen" rel="stylesheet" type="text/css" />
    


        <script src="https://a248.e.akamai.net/assets.github.com/assets/frameworks-d61440caec5d2210a2242b084cdb2bc6597e00b7.js" type="text/javascript"></script>
      <script src="https://a248.e.akamai.net/assets.github.com/assets/github-089ad85d7bd16439d94518cf478e48592191e07d.js" type="text/javascript"></script>
      

        <link rel='permalink' href='/jahennen/CSS_343/blob/2dab9dabe4d6885cb194309ddfb8efd0704f6a1a/HW2/src/BTree.h'>
    <meta property="og:title" content="CSS_343"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/jahennen/CSS_343"/>
    <meta property="og:image" content="https://secure.gravatar.com/avatar/71efc99a775297691be0b419696c02f4?s=420&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="Contribute to CSS_343 development by creating an account on GitHub."/>
    <meta property="twitter:card" content="summary"/>
    <meta property="twitter:site" content="@GitHub">
    <meta property="twitter:title" content="jahennen/CSS_343"/>

    <meta name="description" content="Contribute to CSS_343 development by creating an account on GitHub." />

  <link href="https://github.com/jahennen/CSS_343/commits/master.atom" rel="alternate" title="Recent Commits to CSS_343:master" type="application/atom+xml" />

  </head>


  <body class="logged_in page-blob linux vis-public env-production  ">
    <div id="wrapper">

      

      

      


        <div class="header header-logged-in true">
          <div class="container clearfix">

            <a class="header-logo-blacktocat" href="https://github.com/">
  <span class="mega-icon mega-icon-blacktocat"></span>
</a>

            <div class="divider-vertical"></div>

              <a href="/notifications" class="notification-indicator tooltipped downwards" title="You have no unread notifications">
    <span class="mail-status all-read"></span>
  </a>
  <div class="divider-vertical"></div>


              <div class="topsearch command-bar-activated ">
  <form accept-charset="UTF-8" action="/search" class="command_bar_form" id="top_search_form" method="get">
  <a href="/search/advanced" class="advanced-search-icon tooltipped downwards command-bar-search" id="advanced_search" title="Advanced search"><span class="mini-icon mini-icon-advanced-search "></span></a>

  <input type="text" name="q" id="command-bar" placeholder="Search or type a command" tabindex="1" data-username="jahennen" autocapitalize="off">

  <span class="mini-icon help tooltipped downwards" title="Show command bar help">
    <span class="mini-icon mini-icon-help"></span>
  </span>

  <input type="hidden" name="ref" value="commandbar">

  <div class="divider-vertical"></div>
</form>
  <ul class="top-nav">
      <li class="explore"><a href="https://github.com/explore">Explore</a></li>
      <li><a href="https://gist.github.com">Gist</a></li>
      <li><a href="/blog">Blog</a></li>
    <li><a href="http://help.github.com">Help</a></li>
  </ul>
</div>


            

  
    <ul id="user-links">
      <li>
        <a href="https://github.com/jahennen" class="name">
          <img height="20" src="https://secure.gravatar.com/avatar/71efc99a775297691be0b419696c02f4?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-user-420.png" width="20" /> jahennen
        </a>
      </li>
      <li>
        <a href="/new" id="new_repo" class="tooltipped downwards" title="Create a new repo">
          <span class="mini-icon mini-icon-create"></span>
        </a>
      </li>
      <li>
        <a href="/settings/profile" id="account_settings"
          class="tooltipped downwards"
          title="Account settings ">
          <span class="mini-icon mini-icon-account-settings"></span>
        </a>
      </li>
      <li>
          <a href="/logout" data-method="post" id="logout" class="tooltipped downwards" title="Sign out">
            <span class="mini-icon mini-icon-logout"></span>
          </a>
      </li>
    </ul>



            
          </div>
        </div>


      

      


            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="hentry">
        
        <div class="pagehead repohead instapaper_ignore readability-menu">
          <div class="container">
            <div class="title-actions-bar">
              


<ul class="pagehead-actions">

    <li class="nspr">
      <a href="/jahennen/CSS_343/pull/new/master" class="button minibutton btn-pull-request" icon_class="mini-icon-pull-request"><span class="mini-icon mini-icon-pull-request"></span>Pull Request</a>
    </li>

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="JadKVnVOmD6VSK+zaG6jpeVWZSpcNRaYEmn0R6U5k1w=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="7573568" />

    <div class="select-menu js-menu-container js-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">
          <span class="mini-icon mini-icon-watching"></span>
          Watch
        </span>
      </span>

      <div class="select-menu-modal-holder js-menu-content">
        <div class="select-menu-modal">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container js-select-menu-pane">

            <div class="select-menu-item js-navigation-item js-navigation-target selected">
              <span class="select-menu-checkmark mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for discussions in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-watching"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item js-navigation-target ">
              <span class="select-menu-checkmark mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item js-navigation-target ">
              <span class="select-menu-checkmark mini-icon mini-icon-confirm"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for discussions in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="mini-icon mini-icon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

    <li class="js-toggler-container js-social-container starring-container ">
      <a href="/jahennen/CSS_343/unstar" class="minibutton js-toggler-target star-button starred" data-remote="true" data-method="post" rel="nofollow"><span class="mini-icon mini-icon-remove-star"></span>
      </a><a href="/jahennen/CSS_343/star" class="minibutton js-toggler-target star-button unstarred" data-remote="true" data-method="post" rel="nofollow">
        <span class="mini-icon mini-icon-star"></span></a><a class="social-count js-social-count" href="/jahennen/CSS_343/stargazers">0</a>
    </li>

        <li><a href="/jahennen/CSS_343/fork" class="minibutton js-toggler-target fork-button lighter" rel="nofollow" data-method="post"><span class="mini-icon mini-icon-branch-create"></span></a><a href="/jahennen/CSS_343/network" class="social-count">0</a>
        </li>


</ul>

              <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
                <span class="repo-label"><span>public</span></span>
                <span class="mega-icon mega-icon-public-repo"></span>
                <span class="author vcard">
                  <a href="/jahennen" class="url fn" itemprop="url" rel="author">
                  <span itemprop="title">jahennen</span>
                  </a></span> /
                <strong><a href="/jahennen/CSS_343" class="js-current-repository">CSS_343</a></strong>
              </h1>
            </div>

            

  <ul class="tabs">
    <li><a href="/jahennen/CSS_343" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/jahennen/CSS_343/network" highlight="repo_network">Network</a></li>
    <li><a href="/jahennen/CSS_343/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/jahennen/CSS_343/issues" highlight="repo_issues">Issues <span class='counter'>0</span></a></li>

      <li><a href="/jahennen/CSS_343/wiki" highlight="repo_wiki">Wiki</a></li>


    <li><a href="/jahennen/CSS_343/graphs" highlight="repo_graphsrepo_contributors">Graphs</a></li>

      <li>
        <a href="/jahennen/CSS_343/settings">Settings</a>
      </li>

  </ul>
  
<div class="tabnav">

  <span class="tabnav-right">
    <ul class="tabnav-tabs">
          <li><a href="/jahennen/CSS_343/tags" class="tabnav-tab" highlight="repo_tags">Tags <span class="counter blank">0</span></a></li>
    </ul>
    
  </span>

  <div class="tabnav-widget scope">


    <div class="select-menu js-menu-container js-select-menu js-branch-menu">
      <a class="minibutton select-menu-button js-menu-target" data-hotkey="w" data-ref="master">
        <span class="mini-icon mini-icon-branch"></span>
        <i>branch:</i>
        <span class="js-select-button">master</span>
      </a>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container js-select-menu-pane">

        <div class="select-menu-modal js-select-menu-pane">
          <div class="select-menu-header">
            <span class="select-menu-title">Switch branches/tags</span>
            <span class="mini-icon mini-icon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-filters">
            <div class="select-menu-text-filter">
              <input type="text" id="commitish-filter-field" class="js-select-menu-text-filter js-filterable-field js-navigation-enable" placeholder="Find or create a branch…">
            </div> <!-- /.select-menu-text-filter -->
            <div class="select-menu-tabs">
              <ul>
                <li class="select-menu-tab">
                  <a href="#" data-filter="branches" class="js-select-menu-tab selected">Branches</a>
                </li>
                <li class="select-menu-tab">
                  <a href="#" data-filter="tags" class="js-select-menu-tab">Tags</a>
                </li>
              </ul>
            </div><!-- /.select-menu-tabs -->
          </div><!-- /.select-menu-filters -->

          <div class="select-menu-list js-filter-tab js-filter-branches css-truncate" data-filterable-for="commitish-filter-field" data-filterable-type="substring">



              <div class="select-menu-item js-navigation-item js-navigation-target selected">
                <span class="select-menu-checkmark mini-icon mini-icon-confirm"></span>
                <a href="/jahennen/CSS_343/blob/master/HW2/src/BTree.h" class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target" data-name="master" rel="nofollow" title="master">master</a>
              </div> <!-- /.select-menu-item -->

              <form accept-charset="UTF-8" action="/jahennen/CSS_343/branches" class="js-create-branch select-menu-footer select-menu-item select-menu-new-item-form js-navigation-item js-navigation-target js-new-item-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="JadKVnVOmD6VSK+zaG6jpeVWZSpcNRaYEmn0R6U5k1w=" /></div>


                <span class="mini-icon mini-icon-branch-create"></span>
                <div class="select-menu-item-text">
                  <h4>Create branch: <span class="js-new-item-name"></span></h4>
                  <span class="description">from ‘master’</span>
                </div>
                <input type="hidden" name="name" id="name" class="js-new-item-submit" />
                <input type="hidden" name="branch" id="branch" value="master" />

              </form> <!-- /.select-menu-footer -->


          </div> <!-- /.select-menu-list -->


          <div class="select-menu-list js-filter-tab js-filter-tags css-truncate" data-filterable-for="commitish-filter-field" data-filterable-type="substring" style="display:none;">


            <div class="select-menu-no-results js-not-filterable">Nothing to show</div>

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

  </div> <!-- /.scope -->

  <ul class="tabnav-tabs">
    <li><a href="/jahennen/CSS_343" class="selected tabnav-tab" highlight="repo_source">Files</a></li>
    <li><a href="/jahennen/CSS_343/commits/master" class="tabnav-tab" highlight="repo_commits">Commits</a></li>
    <li><a href="/jahennen/CSS_343/branches" class="tabnav-tab" highlight="repo_branches" rel="nofollow">Branches <span class="counter ">1</span></a></li>
  </ul>

</div>

  
  
  


            
          </div>
        </div><!-- /.repohead -->

        <div id="js-repo-pjax-container" class="container context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:b7b452e0caeed952181fb2493ac03ec4 -->
<!-- blob contrib frag key: views10/v8/blob_contributors:v21:b7b452e0caeed952181fb2493ac03ec4 -->


<div id="slider">
    <div class="frame-meta">

      <p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

        <div class="breadcrumb">
          <span class='bold'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jahennen/CSS_343" class="js-slide-to" data-direction="back" itemscope="url"><span itemprop="title">CSS_343</span></a></span></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jahennen/CSS_343/tree/master/HW2" class="js-slide-to" data-direction="back" itemscope="url"><span itemprop="title">HW2</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/jahennen/CSS_343/tree/master/HW2/src" class="js-slide-to" data-direction="back" itemscope="url"><span itemprop="title">src</span></a></span> / <strong class="final-path">BTree.h</strong> <span class="js-zeroclipboard zeroclipboard-button" data-clipboard-text="HW2/src/BTree.h" data-copied-hint="copied!" title="copy to clipboard"><span class="mini-icon mini-icon-clipboard"></span></span>
        </div>

      <a href="/jahennen/CSS_343/find/master" class="js-slide-to" data-hotkey="t" style="display:none">Show File Finder</a>


        <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/jahennen/CSS_343/contributors/master/HW2/src/BTree.h">
          Fetching contributors…

          <div class="participation">
            <p class="loader-loading"><img alt="Octocat-spinner-32-eaf2f5" height="16" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-32-EAF2F5.gif?1340659530" width="16" /></p>
            <p class="loader-error">Cannot retrieve contributors at this time</p>
          </div>
        </div>

    </div><!-- ./.frame-meta -->

    <div class="frames">
      <div class="frame" data-permalink-url="/jahennen/CSS_343/blob/2dab9dabe4d6885cb194309ddfb8efd0704f6a1a/HW2/src/BTree.h" data-title="CSS_343/HW2/src/BTree.h at master · jahennen/CSS_343 · GitHub" data-type="blob">

        <div id="files" class="bubble">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><b class="mini-icon mini-icon-text-file"></b></span>
                <span class="mode" title="File Mode">file</span>
                  <span>530 lines (505 sloc)</span>
                <span>13.557 kb</span>
              </div>
              <div class="actions">
                <div class="button-group">
                        <a class="minibutton"
                           href="/jahennen/CSS_343/edit/master/HW2/src/BTree.h"
                           data-method="post" rel="nofollow" data-hotkey="e">Edit</a>
                  <a href="/jahennen/CSS_343/raw/master/HW2/src/BTree.h" class="button minibutton " id="raw-url">Raw</a>
                    <a href="/jahennen/CSS_343/blame/master/HW2/src/BTree.h" class="button minibutton ">Blame</a>
                  <a href="/jahennen/CSS_343/commits/master/HW2/src/BTree.h" class="button minibutton " rel="nofollow">History</a>
                </div><!-- /.button-group -->
              </div><!-- /.actions -->

            </div>
                <div class="data type-c js-blob-data">
      <table cellpadding="0" cellspacing="0" class="lines">
        <tr>
          <td>
            <pre class="line_numbers"><span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
<span id="L376" rel="#L376">376</span>
<span id="L377" rel="#L377">377</span>
<span id="L378" rel="#L378">378</span>
<span id="L379" rel="#L379">379</span>
<span id="L380" rel="#L380">380</span>
<span id="L381" rel="#L381">381</span>
<span id="L382" rel="#L382">382</span>
<span id="L383" rel="#L383">383</span>
<span id="L384" rel="#L384">384</span>
<span id="L385" rel="#L385">385</span>
<span id="L386" rel="#L386">386</span>
<span id="L387" rel="#L387">387</span>
<span id="L388" rel="#L388">388</span>
<span id="L389" rel="#L389">389</span>
<span id="L390" rel="#L390">390</span>
<span id="L391" rel="#L391">391</span>
<span id="L392" rel="#L392">392</span>
<span id="L393" rel="#L393">393</span>
<span id="L394" rel="#L394">394</span>
<span id="L395" rel="#L395">395</span>
<span id="L396" rel="#L396">396</span>
<span id="L397" rel="#L397">397</span>
<span id="L398" rel="#L398">398</span>
<span id="L399" rel="#L399">399</span>
<span id="L400" rel="#L400">400</span>
<span id="L401" rel="#L401">401</span>
<span id="L402" rel="#L402">402</span>
<span id="L403" rel="#L403">403</span>
<span id="L404" rel="#L404">404</span>
<span id="L405" rel="#L405">405</span>
<span id="L406" rel="#L406">406</span>
<span id="L407" rel="#L407">407</span>
<span id="L408" rel="#L408">408</span>
<span id="L409" rel="#L409">409</span>
<span id="L410" rel="#L410">410</span>
<span id="L411" rel="#L411">411</span>
<span id="L412" rel="#L412">412</span>
<span id="L413" rel="#L413">413</span>
<span id="L414" rel="#L414">414</span>
<span id="L415" rel="#L415">415</span>
<span id="L416" rel="#L416">416</span>
<span id="L417" rel="#L417">417</span>
<span id="L418" rel="#L418">418</span>
<span id="L419" rel="#L419">419</span>
<span id="L420" rel="#L420">420</span>
<span id="L421" rel="#L421">421</span>
<span id="L422" rel="#L422">422</span>
<span id="L423" rel="#L423">423</span>
<span id="L424" rel="#L424">424</span>
<span id="L425" rel="#L425">425</span>
<span id="L426" rel="#L426">426</span>
<span id="L427" rel="#L427">427</span>
<span id="L428" rel="#L428">428</span>
<span id="L429" rel="#L429">429</span>
<span id="L430" rel="#L430">430</span>
<span id="L431" rel="#L431">431</span>
<span id="L432" rel="#L432">432</span>
<span id="L433" rel="#L433">433</span>
<span id="L434" rel="#L434">434</span>
<span id="L435" rel="#L435">435</span>
<span id="L436" rel="#L436">436</span>
<span id="L437" rel="#L437">437</span>
<span id="L438" rel="#L438">438</span>
<span id="L439" rel="#L439">439</span>
<span id="L440" rel="#L440">440</span>
<span id="L441" rel="#L441">441</span>
<span id="L442" rel="#L442">442</span>
<span id="L443" rel="#L443">443</span>
<span id="L444" rel="#L444">444</span>
<span id="L445" rel="#L445">445</span>
<span id="L446" rel="#L446">446</span>
<span id="L447" rel="#L447">447</span>
<span id="L448" rel="#L448">448</span>
<span id="L449" rel="#L449">449</span>
<span id="L450" rel="#L450">450</span>
<span id="L451" rel="#L451">451</span>
<span id="L452" rel="#L452">452</span>
<span id="L453" rel="#L453">453</span>
<span id="L454" rel="#L454">454</span>
<span id="L455" rel="#L455">455</span>
<span id="L456" rel="#L456">456</span>
<span id="L457" rel="#L457">457</span>
<span id="L458" rel="#L458">458</span>
<span id="L459" rel="#L459">459</span>
<span id="L460" rel="#L460">460</span>
<span id="L461" rel="#L461">461</span>
<span id="L462" rel="#L462">462</span>
<span id="L463" rel="#L463">463</span>
<span id="L464" rel="#L464">464</span>
<span id="L465" rel="#L465">465</span>
<span id="L466" rel="#L466">466</span>
<span id="L467" rel="#L467">467</span>
<span id="L468" rel="#L468">468</span>
<span id="L469" rel="#L469">469</span>
<span id="L470" rel="#L470">470</span>
<span id="L471" rel="#L471">471</span>
<span id="L472" rel="#L472">472</span>
<span id="L473" rel="#L473">473</span>
<span id="L474" rel="#L474">474</span>
<span id="L475" rel="#L475">475</span>
<span id="L476" rel="#L476">476</span>
<span id="L477" rel="#L477">477</span>
<span id="L478" rel="#L478">478</span>
<span id="L479" rel="#L479">479</span>
<span id="L480" rel="#L480">480</span>
<span id="L481" rel="#L481">481</span>
<span id="L482" rel="#L482">482</span>
<span id="L483" rel="#L483">483</span>
<span id="L484" rel="#L484">484</span>
<span id="L485" rel="#L485">485</span>
<span id="L486" rel="#L486">486</span>
<span id="L487" rel="#L487">487</span>
<span id="L488" rel="#L488">488</span>
<span id="L489" rel="#L489">489</span>
<span id="L490" rel="#L490">490</span>
<span id="L491" rel="#L491">491</span>
<span id="L492" rel="#L492">492</span>
<span id="L493" rel="#L493">493</span>
<span id="L494" rel="#L494">494</span>
<span id="L495" rel="#L495">495</span>
<span id="L496" rel="#L496">496</span>
<span id="L497" rel="#L497">497</span>
<span id="L498" rel="#L498">498</span>
<span id="L499" rel="#L499">499</span>
<span id="L500" rel="#L500">500</span>
<span id="L501" rel="#L501">501</span>
<span id="L502" rel="#L502">502</span>
<span id="L503" rel="#L503">503</span>
<span id="L504" rel="#L504">504</span>
<span id="L505" rel="#L505">505</span>
<span id="L506" rel="#L506">506</span>
<span id="L507" rel="#L507">507</span>
<span id="L508" rel="#L508">508</span>
<span id="L509" rel="#L509">509</span>
<span id="L510" rel="#L510">510</span>
<span id="L511" rel="#L511">511</span>
<span id="L512" rel="#L512">512</span>
<span id="L513" rel="#L513">513</span>
<span id="L514" rel="#L514">514</span>
<span id="L515" rel="#L515">515</span>
<span id="L516" rel="#L516">516</span>
<span id="L517" rel="#L517">517</span>
<span id="L518" rel="#L518">518</span>
<span id="L519" rel="#L519">519</span>
<span id="L520" rel="#L520">520</span>
<span id="L521" rel="#L521">521</span>
<span id="L522" rel="#L522">522</span>
<span id="L523" rel="#L523">523</span>
<span id="L524" rel="#L524">524</span>
<span id="L525" rel="#L525">525</span>
<span id="L526" rel="#L526">526</span>
<span id="L527" rel="#L527">527</span>
<span id="L528" rel="#L528">528</span>
<span id="L529" rel="#L529">529</span>
</pre>
          </td>
          <td width="100%">
                  <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/*</span></div><div class='line' id='LC2'><span class="cm"> * BTree.h</span></div><div class='line' id='LC3'><span class="cm"> *</span></div><div class='line' id='LC4'><span class="cm"> *  Created on: Jan 20, 2013</span></div><div class='line' id='LC5'><span class="cm"> *      Author: jay</span></div><div class='line' id='LC6'><span class="cm"> */</span></div><div class='line' id='LC7'><br/></div><div class='line' id='LC8'><span class="cp">#ifndef BTREE_H_</span></div><div class='line' id='LC9'><span class="cp">#define BTREE_H_</span></div><div class='line' id='LC10'><br/></div><div class='line' id='LC11'><span class="cp">#include &lt;cstdlib&gt;</span></div><div class='line' id='LC12'><span class="cp">#include &lt;iostream&gt;</span></div><div class='line' id='LC13'><br/></div><div class='line' id='LC14'><span class="n">using</span> <span class="n">namespace</span> <span class="n">std</span><span class="p">;</span></div><div class='line' id='LC15'><br/></div><div class='line' id='LC16'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC17'><span class="n">class</span> <span class="n">BTree</span><span class="p">;</span></div><div class='line' id='LC18'><br/></div><div class='line' id='LC19'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC20'><span class="n">class</span> <span class="n">TreeNode</span> <span class="p">{</span></div><div class='line' id='LC21'>	<span class="n">friend</span> <span class="n">class</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC22'><span class="nl">public:</span></div><div class='line' id='LC23'>	<span class="n">TreeNode</span><span class="p">();</span></div><div class='line' id='LC24'><span class="nl">private:</span></div><div class='line' id='LC25'>	<span class="n">T</span><span class="o">*</span> <span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC26'>	<span class="n">T</span><span class="o">*</span> <span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC27'>	<span class="n">TreeNode</span><span class="o">*</span> <span class="n">left</span><span class="p">;</span> <span class="c1">//pointer to left child node of node</span></div><div class='line' id='LC28'>	<span class="n">TreeNode</span><span class="o">*</span> <span class="n">mid</span><span class="p">;</span> <span class="c1">//pointer to right child node of node</span></div><div class='line' id='LC29'>	<span class="n">TreeNode</span><span class="o">*</span> <span class="n">right</span><span class="p">;</span> <span class="c1">//pointer to right child node of node</span></div><div class='line' id='LC30'><span class="p">};</span></div><div class='line' id='LC31'><br/></div><div class='line' id='LC32'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC33'><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">TreeNode</span><span class="p">()</span></div><div class='line' id='LC34'><span class="p">{</span></div><div class='line' id='LC35'>	<span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC36'>	<span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC37'>	<span class="n">left</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC38'>	<span class="n">mid</span>  <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC39'>	<span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC40'><span class="p">}</span></div><div class='line' id='LC41'><br/></div><div class='line' id='LC42'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC43'><span class="n">class</span> <span class="n">BTree</span> <span class="p">{</span></div><div class='line' id='LC44'><span class="nl">public:</span></div><div class='line' id='LC45'>	<span class="n">BTree</span><span class="p">();</span></div><div class='line' id='LC46'>	<span class="o">~</span><span class="n">BTree</span><span class="p">();</span></div><div class='line' id='LC47'>	<span class="n">T</span><span class="o">*</span> <span class="n">insert</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">);</span></div><div class='line' id='LC48'>	<span class="n">T</span><span class="o">*</span> <span class="n">remove</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">);</span></div><div class='line' id='LC49'>	<span class="n">T</span><span class="o">*</span> <span class="n">lookup</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">);</span></div><div class='line' id='LC50'>	<span class="n">bool</span> <span class="n">is_empty</span><span class="p">();</span></div><div class='line' id='LC51'>	<span class="kt">void</span> <span class="n">dump_tree</span><span class="p">();</span></div><div class='line' id='LC52'>	<span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">F</span><span class="o">&gt;</span></div><div class='line' id='LC53'>	<span class="kt">void</span> <span class="n">walk</span><span class="p">(</span><span class="n">F</span> <span class="n">f</span><span class="p">);</span></div><div class='line' id='LC54'><span class="nl">private:</span></div><div class='line' id='LC55'>	<span class="kt">void</span> <span class="n">clean_up</span><span class="p">(</span><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">);</span></div><div class='line' id='LC56'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">root</span><span class="p">;</span></div><div class='line' id='LC57'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">re_lookup</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">);</span></div><div class='line' id='LC58'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">recursive_insert</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">);</span></div><div class='line' id='LC59'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">recursive_remove</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">);</span></div><div class='line' id='LC60'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">find_parent</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">child</span><span class="p">);</span></div><div class='line' id='LC61'>	<span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">F</span><span class="o">&gt;</span></div><div class='line' id='LC62'>	<span class="kt">void</span> <span class="n">re_walk</span><span class="p">(</span><span class="n">F</span> <span class="n">f</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">);</span></div><div class='line' id='LC63'>	<span class="kt">void</span> <span class="n">fix</span><span class="p">(</span><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">hole</span><span class="p">);</span></div><div class='line' id='LC64'><span class="p">};</span></div><div class='line' id='LC65'><br/></div><div class='line' id='LC66'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC67'><span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">BTree</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC68'>	<span class="n">root</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC69'><span class="p">}</span></div><div class='line' id='LC70'><br/></div><div class='line' id='LC71'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC72'><span class="kt">void</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">clean_up</span><span class="p">(</span><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC73'>	<span class="k">if</span> <span class="p">(</span><span class="n">is_empty</span><span class="p">())</span> <span class="p">{</span> <span class="c1">// nothing to do</span></div><div class='line' id='LC74'>		<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC75'>	<span class="p">}</span></div><div class='line' id='LC76'>	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">)</span> <span class="p">{</span> <span class="c1">//Leaf</span></div><div class='line' id='LC77'>		<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC78'>		<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span></div><div class='line' id='LC79'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC80'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC81'>		<span class="n">clean_up</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">);</span></div><div class='line' id='LC82'>		<span class="n">delete</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC83'>		<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC84'>		<span class="n">clean_up</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC85'>		<span class="n">delete</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC86'>		<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC87'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC88'>			<span class="n">clean_up</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">);</span></div><div class='line' id='LC89'>			<span class="n">delete</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC90'>		<span class="p">}</span></div><div class='line' id='LC91'>	<span class="p">}</span></div><div class='line' id='LC92'><span class="p">}</span></div><div class='line' id='LC93'><br/></div><div class='line' id='LC94'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC95'><span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::~</span><span class="n">BTree</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC96'>	<span class="n">clean_up</span><span class="p">(</span><span class="n">root</span><span class="p">);</span></div><div class='line' id='LC97'>	<span class="n">delete</span> <span class="n">root</span><span class="p">;</span></div><div class='line' id='LC98'><span class="p">}</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC101'><span class="n">bool</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">is_empty</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC102'>	<span class="k">return</span> <span class="n">root</span> <span class="o">==</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC103'><span class="p">}</span></div><div class='line' id='LC104'><br/></div><div class='line' id='LC105'><br/></div><div class='line' id='LC106'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC107'><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">re_lookup</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC108'>	<span class="k">if</span> <span class="p">(</span><span class="n">current</span> <span class="o">==</span> <span class="nb">NULL</span><span class="p">)</span></div><div class='line' id='LC109'>		<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC110'>	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span><span class="o">&amp;&amp;!</span><span class="p">(</span><span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">))</span></div><div class='line' id='LC111'>		<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC112'>	<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span><span class="o">&amp;&amp;!</span><span class="p">(</span><span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">))</span></div><div class='line' id='LC113'>		<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC114'>	<span class="k">if</span> <span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span></div><div class='line' id='LC115'>		<span class="k">return</span> <span class="n">re_lookup</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">);</span></div><div class='line' id='LC116'>	<span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&amp;&amp;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">)</span></div><div class='line' id='LC117'>		<span class="k">return</span> <span class="n">re_lookup</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">);</span></div><div class='line' id='LC118'>	<span class="k">else</span></div><div class='line' id='LC119'>		<span class="k">return</span> <span class="n">re_lookup</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC120'><span class="p">}</span></div><div class='line' id='LC121'><br/></div><div class='line' id='LC122'><br/></div><div class='line' id='LC123'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC124'><span class="n">T</span><span class="o">*</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">lookup</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC125'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">result</span> <span class="o">=</span> <span class="n">re_lookup</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">root</span><span class="p">);</span></div><div class='line' id='LC126'>	<span class="k">if</span> <span class="p">(</span><span class="n">result</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC127'>		<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span><span class="o">&amp;&amp;!</span><span class="p">(</span><span class="o">*</span><span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">))</span></div><div class='line' id='LC128'>			<span class="k">return</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC129'>		<span class="k">if</span> <span class="p">(</span><span class="n">result</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">result</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span><span class="o">&amp;&amp;!</span><span class="p">(</span><span class="o">*</span><span class="n">result</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">))</span></div><div class='line' id='LC130'>			<span class="k">return</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC131'>	<span class="p">}</span></div><div class='line' id='LC132'>	<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC133'><span class="p">}</span></div><div class='line' id='LC134'><br/></div><div class='line' id='LC135'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC136'><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">recursive_insert</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">current</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC137'>	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">)</span> <span class="p">{</span>	<span class="c1">//base case (leaf node)</span></div><div class='line' id='LC138'>		<span class="c1">//case 1 key space available</span></div><div class='line' id='LC139'>		<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC140'>			<span class="k">if</span> <span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC141'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC142'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC143'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC144'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC145'>			<span class="p">}</span></div><div class='line' id='LC146'>			<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC147'>			<span class="c1">//case 2 node is full, so split</span></div><div class='line' id='LC148'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC149'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC150'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC151'>			<span class="k">if</span> <span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC152'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC153'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC154'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC155'>				<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC156'>			<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC157'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC158'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC159'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC160'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC161'>				<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC162'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC163'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC164'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC165'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC166'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC167'>				<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC168'>			<span class="p">}</span></div><div class='line' id='LC169'>		<span class="p">}</span></div><div class='line' id='LC170'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>	<span class="c1">// Recursive case, choose a path</span></div><div class='line' id='LC171'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">l</span><span class="p">;</span></div><div class='line' id='LC172'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">r</span><span class="p">;</span></div><div class='line' id='LC173'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">result</span><span class="p">;</span></div><div class='line' id='LC174'>		<span class="k">if</span> <span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// Left path</span></div><div class='line' id='LC175'>			<span class="n">result</span> <span class="o">=</span> <span class="n">recursive_insert</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">);</span></div><div class='line' id='LC176'>			<span class="k">if</span> <span class="p">(</span><span class="n">result</span> <span class="o">!=</span> <span class="nb">NULL</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// Uh oh, need to split?</span></div><div class='line' id='LC177'>				<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">//Node is full, split</span></div><div class='line' id='LC178'>					<span class="n">l</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC179'>					<span class="n">r</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC180'>					<span class="n">l</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC181'>					<span class="n">r</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC182'>					<span class="n">l</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC183'>					<span class="n">l</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC184'>					<span class="n">r</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC185'>					<span class="n">r</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC186'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// Node is not full</span></div><div class='line' id='LC187'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC188'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC189'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC190'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC191'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC192'>					<span class="n">delete</span> <span class="n">result</span><span class="p">;</span> <span class="c1">//result has been merged</span></div><div class='line' id='LC193'>					<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC194'>				<span class="p">}</span></div><div class='line' id='LC195'>			<span class="p">}</span></div><div class='line' id='LC196'>		<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&amp;&amp;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// right path</span></div><div class='line' id='LC197'>			<span class="n">result</span> <span class="o">=</span> <span class="n">recursive_insert</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">);</span></div><div class='line' id='LC198'>			<span class="k">if</span> <span class="p">(</span><span class="n">result</span> <span class="o">!=</span> <span class="nb">NULL</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// Uh oh, need to split?</span></div><div class='line' id='LC199'>				<span class="n">l</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC200'>				<span class="n">r</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC201'>				<span class="n">l</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC202'>				<span class="n">r</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC203'>				<span class="n">l</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC204'>				<span class="n">l</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC205'>				<span class="n">r</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC206'>				<span class="n">r</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC207'>				<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC208'>			<span class="p">}</span></div><div class='line' id='LC209'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// mid path</span></div><div class='line' id='LC210'>			<span class="n">result</span> <span class="o">=</span> <span class="n">recursive_insert</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC211'>			<span class="k">if</span> <span class="p">(</span><span class="n">result</span> <span class="o">!=</span> <span class="nb">NULL</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// Uh oh, need to split?</span></div><div class='line' id='LC212'>				<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">//Node is full, split</span></div><div class='line' id='LC213'>					<span class="n">l</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC214'>					<span class="n">r</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC215'>					<span class="n">l</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC216'>					<span class="n">r</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC217'>					<span class="n">l</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC218'>					<span class="n">l</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC219'>					<span class="n">r</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC220'>					<span class="n">r</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC221'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC222'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// Node is not full</span></div><div class='line' id='LC223'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC224'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC225'>					<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">result</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC226'>					<span class="n">delete</span> <span class="n">result</span><span class="p">;</span> <span class="c1">//result has been merged</span></div><div class='line' id='LC227'>					<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC228'>				<span class="p">}</span></div><div class='line' id='LC229'>			<span class="p">}</span></div><div class='line' id='LC230'>		<span class="p">}</span></div><div class='line' id='LC231'>		<span class="k">if</span> <span class="p">(</span><span class="n">result</span><span class="p">){</span></div><div class='line' id='LC232'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC233'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">l</span><span class="p">;</span></div><div class='line' id='LC234'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">r</span><span class="p">;</span></div><div class='line' id='LC235'>			<span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC236'>			<span class="n">delete</span> <span class="n">result</span><span class="p">;</span> <span class="c1">//result has been merged</span></div><div class='line' id='LC237'>			<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC238'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC239'>			<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC240'>		<span class="p">}</span></div><div class='line' id='LC241'>	<span class="p">}</span></div><div class='line' id='LC242'>	<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span> <span class="c1">//SHOULD NOT REACH HERE</span></div><div class='line' id='LC243'><span class="p">}</span></div><div class='line' id='LC244'><br/></div><div class='line' id='LC245'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC246'><span class="n">T</span><span class="o">*</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">insert</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC247'>	<span class="n">T</span><span class="o">*</span> <span class="n">res</span> <span class="o">=</span> <span class="n">lookup</span><span class="p">(</span><span class="n">item</span><span class="p">);</span></div><div class='line' id='LC248'>	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">res</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC249'>		<span class="k">if</span> <span class="p">(</span><span class="n">is_empty</span><span class="p">())</span> <span class="p">{</span></div><div class='line' id='LC250'>			<span class="n">root</span> <span class="o">=</span> <span class="n">new</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span><span class="p">;</span></div><div class='line' id='LC251'>			<span class="n">root</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC252'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC253'>			<span class="n">recursive_insert</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">root</span><span class="p">);</span></div><div class='line' id='LC254'>		<span class="p">}</span></div><div class='line' id='LC255'>		<span class="k">return</span> <span class="n">lookup</span><span class="p">(</span><span class="n">item</span><span class="p">);</span></div><div class='line' id='LC256'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC257'>		<span class="k">return</span> <span class="n">res</span><span class="p">;</span></div><div class='line' id='LC258'>	<span class="p">}</span></div><div class='line' id='LC259'><span class="p">}</span></div><div class='line' id='LC260'><br/></div><div class='line' id='LC261'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC262'><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">find_parent</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">child</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC263'>	<span class="k">if</span> <span class="p">(</span><span class="n">current</span> <span class="o">==</span> <span class="n">child</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC264'>		<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC265'>	<span class="p">}</span></div><div class='line' id='LC266'>	<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">==</span> <span class="n">child</span> <span class="o">||</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">==</span> <span class="n">child</span> <span class="o">||</span></div><div class='line' id='LC267'>			<span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">&amp;&amp;</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">==</span> <span class="n">child</span><span class="p">))</span> <span class="p">{</span>	<span class="c1">//base case, this node is parent</span></div><div class='line' id='LC268'>		<span class="k">return</span> <span class="n">current</span><span class="p">;</span></div><div class='line' id='LC269'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// use item to path down the tree</span></div><div class='line' id='LC270'>		<span class="k">if</span> <span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">)</span></div><div class='line' id='LC271'>			<span class="k">return</span> <span class="n">find_parent</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">,</span> <span class="n">child</span><span class="p">);</span></div><div class='line' id='LC272'>		<span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&amp;&amp;</span> <span class="o">*</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">)</span></div><div class='line' id='LC273'>			<span class="k">return</span> <span class="n">find_parent</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">,</span> <span class="n">child</span><span class="p">);</span></div><div class='line' id='LC274'>		<span class="k">else</span></div><div class='line' id='LC275'>			<span class="k">return</span> <span class="n">find_parent</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">,</span> <span class="n">child</span><span class="p">);</span></div><div class='line' id='LC276'>	<span class="p">}</span></div><div class='line' id='LC277'><span class="p">}</span></div><div class='line' id='LC278'><br/></div><div class='line' id='LC279'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC280'><span class="kt">void</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">fix</span><span class="p">(</span><span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">parent</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">hole</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC281'>	<span class="k">if</span> <span class="p">(</span><span class="n">hole</span> <span class="o">==</span> <span class="n">root</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC282'>		<span class="n">root</span> <span class="o">=</span> <span class="n">hole</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span> <span class="c1">//TEMPORARY</span></div><div class='line' id='LC283'>		<span class="n">delete</span><span class="p">(</span><span class="n">hole</span><span class="p">);</span></div><div class='line' id='LC284'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC285'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">lc</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span>  <span class="c1">//left child</span></div><div class='line' id='LC286'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">mc</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span>	 <span class="c1">//mid child</span></div><div class='line' id='LC287'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">rc</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span> <span class="c1">//right child</span></div><div class='line' id='LC288'>		<span class="k">if</span> <span class="p">(</span><span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// parent has 2 keys, therefore 3 children</span></div><div class='line' id='LC289'>			<span class="k">if</span><span class="p">(</span><span class="n">lc</span> <span class="o">==</span> <span class="n">hole</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is left</span></div><div class='line' id='LC290'>				<span class="k">if</span> <span class="p">(</span><span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is left node, middle is full</span></div><div class='line' id='LC291'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC292'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC293'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC294'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC295'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC296'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC297'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC298'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC299'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC300'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC301'>				<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">rc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">){</span> <span class="c1">//hole is left, middle sibling has 1 key, right full</span></div><div class='line' id='LC302'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC303'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC304'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC305'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC306'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC307'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC308'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC309'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC310'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC311'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC312'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC313'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC314'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC315'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC316'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// hole is left, mid, right have 1 key</span></div><div class='line' id='LC317'>					<span class="c1">// earrange keys</span></div><div class='line' id='LC318'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC319'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC320'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC321'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC322'>					<span class="c1">// shift ptrs</span></div><div class='line' id='LC323'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC324'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC325'>					<span class="n">delete</span><span class="p">(</span><span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC326'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC327'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC328'>				<span class="p">}</span></div><div class='line' id='LC329'>				<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC330'>			<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">mc</span> <span class="o">==</span> <span class="n">hole</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is mid</span></div><div class='line' id='LC331'>				<span class="k">if</span> <span class="p">(</span><span class="n">rc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is mid, right full</span></div><div class='line' id='LC332'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC333'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC334'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC335'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC336'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC337'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC338'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC339'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC340'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC341'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC342'>				<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">//hole is mid, left is full, right has 1</span></div><div class='line' id='LC343'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC344'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC345'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC346'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC347'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC348'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC349'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC350'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC351'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">//hole is mid, left has 1, right has 1</span></div><div class='line' id='LC352'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC353'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC354'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC355'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC356'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC357'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC358'>					<span class="n">delete</span><span class="p">(</span><span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC359'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC360'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC361'>				<span class="p">}</span></div><div class='line' id='LC362'>				<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC363'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// hole is right</span></div><div class='line' id='LC364'>				<span class="k">if</span> <span class="p">(</span><span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is right, mid is full</span></div><div class='line' id='LC365'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC366'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC367'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC368'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC369'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC370'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC371'>					<span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC372'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC373'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// hole is right, mid has 1</span></div><div class='line' id='LC374'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC375'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC376'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC377'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC378'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">rc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC379'>					<span class="n">delete</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC380'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC381'>				<span class="p">}</span></div><div class='line' id='LC382'>				<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC383'>			<span class="p">}</span></div><div class='line' id='LC384'><br/></div><div class='line' id='LC385'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// Parent has 1 key. Might need to push hole upwards</span></div><div class='line' id='LC386'>			<span class="k">if</span><span class="p">(</span><span class="n">lc</span> <span class="o">==</span> <span class="n">hole</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is left</span></div><div class='line' id='LC387'>				<span class="k">if</span> <span class="p">(</span><span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">//hole is left, mid is full</span></div><div class='line' id='LC388'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC389'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC390'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC391'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC392'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC393'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC394'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC395'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC396'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC397'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC398'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">//hole is left, mid has 1</span></div><div class='line' id='LC399'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC400'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC401'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC402'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC403'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC404'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC405'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC406'>					<span class="n">delete</span><span class="p">(</span><span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC407'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span> <span class="c1">//Parent is new hole</span></div><div class='line' id='LC408'>					<span class="n">fix</span><span class="p">(</span><span class="n">find_parent</span><span class="p">(</span><span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">,</span><span class="n">root</span><span class="p">,</span><span class="n">parent</span><span class="p">),</span> <span class="n">parent</span><span class="p">);</span></div><div class='line' id='LC409'>				<span class="p">}</span></div><div class='line' id='LC410'>			<span class="p">}</span> <span class="k">else</span> <span class="k">if</span> <span class="p">(</span><span class="n">mc</span> <span class="o">==</span> <span class="n">hole</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC411'>				<span class="k">if</span> <span class="p">(</span><span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// hole is mid, left is full</span></div><div class='line' id='LC412'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC413'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC414'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC415'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC416'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC417'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC418'>					<span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">=</span> <span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC419'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC420'>				<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC421'>					<span class="c1">//rearrange keys</span></div><div class='line' id='LC422'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC423'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC424'>					<span class="c1">//shift ptrs</span></div><div class='line' id='LC425'>					<span class="n">lc</span><span class="o">-&gt;</span><span class="n">right</span> <span class="o">=</span> <span class="n">mc</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC426'>					<span class="n">delete</span><span class="p">(</span><span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC427'>					<span class="n">parent</span><span class="o">-&gt;</span><span class="n">mid</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span> <span class="c1">//Parent is new hole</span></div><div class='line' id='LC428'>					<span class="n">fix</span><span class="p">(</span><span class="n">find_parent</span><span class="p">(</span><span class="n">lc</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">,</span><span class="n">root</span><span class="p">,</span><span class="n">parent</span><span class="p">),</span> <span class="n">parent</span><span class="p">);</span></div><div class='line' id='LC429'>				<span class="p">}</span></div><div class='line' id='LC430'>			<span class="p">}</span></div><div class='line' id='LC431'>		<span class="p">}</span></div><div class='line' id='LC432'>	<span class="p">}</span></div><div class='line' id='LC433'>	<span class="k">return</span><span class="p">;</span></div><div class='line' id='LC434'><span class="p">}</span></div><div class='line' id='LC435'><br/></div><div class='line' id='LC436'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC437'><span class="n">T</span><span class="o">*</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">remove</span><span class="p">(</span><span class="n">T</span><span class="o">*</span> <span class="n">item</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC438'>	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">lookup</span><span class="p">(</span><span class="n">item</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC439'>		<span class="k">return</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC440'>	<span class="p">}</span></div><div class='line' id='LC441'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">hole</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC442'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">parent</span><span class="p">;</span></div><div class='line' id='LC443'>	<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">location</span><span class="p">;</span></div><div class='line' id='LC444'>	<span class="kt">int</span> <span class="n">loc_replacee</span><span class="p">;</span> <span class="c1">// location key # to be replaced</span></div><div class='line' id='LC445'>	<span class="c1">//if (root-&gt;key1 == item || root-&gt;key2 == item) {</span></div><div class='line' id='LC446'>		<span class="n">location</span> <span class="o">=</span> <span class="n">re_lookup</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">root</span><span class="p">);</span> <span class="c1">// find the location to remove</span></div><div class='line' id='LC447'>	<span class="k">if</span> <span class="p">(</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">)</span> <span class="p">{</span>	<span class="c1">// deleting from a branch node, find immediate predecessor</span></div><div class='line' id='LC448'>		<span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;*</span> <span class="n">pred</span><span class="p">;</span> <span class="c1">// need the predecessor</span></div><div class='line' id='LC449'>		<span class="k">if</span> <span class="p">(</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">)</span> <span class="p">)</span> <span class="p">{</span> <span class="c1">// remove location-&gt;key2</span></div><div class='line' id='LC450'>			<span class="n">pred</span> <span class="o">=</span> <span class="n">location</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC451'>			<span class="n">loc_replacee</span> <span class="o">=</span> <span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC452'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>	<span class="c1">// remove location-&gt;key1</span></div><div class='line' id='LC453'>			<span class="n">pred</span> <span class="o">=</span> <span class="n">location</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">;</span></div><div class='line' id='LC454'>			<span class="n">loc_replacee</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC455'>		<span class="p">}</span></div><div class='line' id='LC456'>		<span class="k">while</span> <span class="p">(</span><span class="n">pred</span><span class="o">-&gt;</span><span class="n">left</span> <span class="o">!=</span> <span class="nb">NULL</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// walk to find pred;</span></div><div class='line' id='LC457'>			<span class="k">if</span> <span class="p">(</span><span class="n">pred</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC458'>				<span class="n">pred</span> <span class="o">=</span> <span class="n">pred</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">;</span></div><div class='line' id='LC459'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC460'>				<span class="n">pred</span> <span class="o">=</span> <span class="n">pred</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">;</span></div><div class='line' id='LC461'>			<span class="p">}</span></div><div class='line' id='LC462'>		<span class="p">}</span></div><div class='line' id='LC463'>		<span class="n">parent</span> <span class="o">=</span> <span class="n">find_parent</span><span class="p">(</span><span class="n">pred</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">,</span> <span class="n">root</span><span class="p">,</span> <span class="n">pred</span><span class="p">);</span></div><div class='line' id='LC464'>		<span class="k">if</span> <span class="p">(</span><span class="n">loc_replacee</span> <span class="o">==</span> <span class="mi">2</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// remove location-&gt;key2</span></div><div class='line' id='LC465'>			<span class="k">if</span> <span class="p">(</span><span class="n">pred</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC466'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">pred</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC467'>				<span class="n">pred</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC468'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">//Removing will empty the leaf, creating a hole</span></div><div class='line' id='LC469'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="n">pred</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC470'>				<span class="n">pred</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC471'>				<span class="n">hole</span> <span class="o">=</span> <span class="n">pred</span><span class="p">;</span></div><div class='line' id='LC472'>			<span class="p">}</span></div><div class='line' id='LC473'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span>	<span class="c1">// remove location-&gt;key1</span></div><div class='line' id='LC474'>			<span class="k">if</span> <span class="p">(</span><span class="n">pred</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC475'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">pred</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC476'>				<span class="n">pred</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC477'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">//Removing will empty t=he leaf, creating a hole</span></div><div class='line' id='LC478'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">pred</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">;</span></div><div class='line' id='LC479'>				<span class="n">pred</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC480'>				<span class="n">hole</span> <span class="o">=</span> <span class="n">pred</span><span class="p">;</span></div><div class='line' id='LC481'>			<span class="p">}</span></div><div class='line' id='LC482'>		<span class="p">}</span></div><div class='line' id='LC483'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// Removing from a leaf</span></div><div class='line' id='LC484'>		<span class="n">parent</span> <span class="o">=</span> <span class="n">find_parent</span><span class="p">(</span><span class="n">item</span><span class="p">,</span> <span class="n">root</span><span class="p">,</span> <span class="n">location</span><span class="p">);</span></div><div class='line' id='LC485'>		<span class="k">if</span> <span class="p">(</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC486'>			<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">item</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="o">!</span><span class="p">(</span><span class="o">*</span><span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">&lt;</span> <span class="o">*</span><span class="n">item</span><span class="p">)</span> <span class="p">){</span></div><div class='line' id='LC487'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC488'>			<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC489'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">;</span></div><div class='line' id='LC490'>				<span class="n">location</span><span class="o">-&gt;</span><span class="n">key2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC491'>			<span class="p">}</span></div><div class='line' id='LC492'>		<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">//Removing will empty the leaf, creating a hole</span></div><div class='line' id='LC493'>			<span class="n">location</span><span class="o">-&gt;</span><span class="n">key1</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC494'>			<span class="n">hole</span> <span class="o">=</span> <span class="n">location</span><span class="p">;</span></div><div class='line' id='LC495'>		<span class="p">}</span></div><div class='line' id='LC496'>	<span class="p">}</span></div><div class='line' id='LC497'>	<span class="c1">// Okay, item has been deleted, now deal with the hole, if one was created</span></div><div class='line' id='LC498'>	<span class="k">if</span> <span class="p">(</span><span class="n">hole</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC499'>		<span class="n">fix</span><span class="p">(</span><span class="n">parent</span><span class="p">,</span> <span class="n">hole</span><span class="p">);</span></div><div class='line' id='LC500'>	<span class="p">}</span></div><div class='line' id='LC501'>	<span class="k">return</span> <span class="n">item</span><span class="p">;</span></div><div class='line' id='LC502'><span class="p">}</span></div><div class='line' id='LC503'><br/></div><div class='line' id='LC504'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC505'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">F</span><span class="o">&gt;</span></div><div class='line' id='LC506'><span class="kt">void</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">re_walk</span><span class="p">(</span><span class="n">F</span> <span class="n">f</span><span class="p">,</span> <span class="n">TreeNode</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;</span> <span class="o">*</span> <span class="n">current</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC507'>	<span class="k">if</span> <span class="p">(</span><span class="o">!</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">)</span> <span class="p">{</span> <span class="c1">//base case, leaf node</span></div><div class='line' id='LC508'>		<span class="n">f</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">);</span></div><div class='line' id='LC509'>		<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC510'>			<span class="n">f</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">);</span></div><div class='line' id='LC511'>		<span class="p">}</span></div><div class='line' id='LC512'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span> <span class="c1">// recursive case, process inorder</span></div><div class='line' id='LC513'>		<span class="n">re_walk</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">left</span><span class="p">);</span></div><div class='line' id='LC514'>		<span class="n">f</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key1</span><span class="p">);</span></div><div class='line' id='LC515'>		<span class="n">re_walk</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">mid</span><span class="p">);</span></div><div class='line' id='LC516'>		<span class="k">if</span> <span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC517'>			<span class="n">f</span><span class="p">(</span><span class="n">current</span><span class="o">-&gt;</span><span class="n">key2</span><span class="p">);</span></div><div class='line' id='LC518'>			<span class="n">re_walk</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="n">current</span><span class="o">-&gt;</span><span class="n">right</span><span class="p">);</span></div><div class='line' id='LC519'>		<span class="p">}</span></div><div class='line' id='LC520'>	<span class="p">}</span></div><div class='line' id='LC521'><span class="p">}</span></div><div class='line' id='LC522'><br/></div><div class='line' id='LC523'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">T</span><span class="o">&gt;</span></div><div class='line' id='LC524'><span class="n">template</span> <span class="o">&lt;</span><span class="kr">typename</span> <span class="n">F</span><span class="o">&gt;</span></div><div class='line' id='LC525'><span class="kt">void</span> <span class="n">BTree</span><span class="o">&lt;</span><span class="n">T</span><span class="o">&gt;::</span><span class="n">walk</span><span class="p">(</span><span class="n">F</span> <span class="n">f</span><span class="p">)</span> <span class="p">{</span> <span class="c1">// does an inorder walk of the tree</span></div><div class='line' id='LC526'>	<span class="n">re_walk</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="n">root</span><span class="p">);</span></div><div class='line' id='LC527'><span class="p">}</span></div><div class='line' id='LC528'><br/></div><div class='line' id='LC529'><span class="cp">#endif </span><span class="cm">/* BTREE_H_ */</span><span class="cp"></span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>

        <a href="#jump-to-line" rel="facebox" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
        <div id="jump-to-line" style="display:none">
          <h2>Jump to Line</h2>
          <form accept-charset="UTF-8" class="js-jump-to-line-form">
            <input class="textfield js-jump-to-line-field" type="text">
            <div class="full-button">
              <button type="submit" class="button">Go</button>
            </div>
          </form>
        </div>

      </div>
    </div>
</div>

<div id="js-frame-loading-template" class="frame frame-loading large-loading-area" style="display:none;">
  <img class="js-frame-loading-spinner" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-128.gif?1347543525" height="64" width="64">
</div>


        </div>
      </div>
      <div class="context-overlay"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer">
  <div class="container clearfix">

      <dl class="footer_nav">
        <dt>GitHub</dt>
        <dd><a href="https://github.com/about">About us</a></dd>
        <dd><a href="https://github.com/blog">Blog</a></dd>
        <dd><a href="https://github.com/contact">Contact &amp; support</a></dd>
        <dd><a href="http://enterprise.github.com/">GitHub Enterprise</a></dd>
        <dd><a href="http://status.github.com/">Site status</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Applications</dt>
        <dd><a href="http://mac.github.com/">GitHub for Mac</a></dd>
        <dd><a href="http://windows.github.com/">GitHub for Windows</a></dd>
        <dd><a href="http://eclipse.github.com/">GitHub for Eclipse</a></dd>
        <dd><a href="http://mobile.github.com/">GitHub mobile apps</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Services</dt>
        <dd><a href="http://get.gaug.es/">Gauges: Web analytics</a></dd>
        <dd><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></dd>
        <dd><a href="https://gist.github.com">Gist: Code snippets</a></dd>
        <dd><a href="http://jobs.github.com/">Job board</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>Documentation</dt>
        <dd><a href="http://help.github.com/">GitHub Help</a></dd>
        <dd><a href="http://developer.github.com/">Developer API</a></dd>
        <dd><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></dd>
        <dd><a href="http://pages.github.com/">GitHub Pages</a></dd>
      </dl>

      <dl class="footer_nav">
        <dt>More</dt>
        <dd><a href="http://training.github.com/">Training</a></dd>
        <dd><a href="https://github.com/edu">Students &amp; teachers</a></dd>
        <dd><a href="http://shop.github.com">The Shop</a></dd>
        <dd><a href="/plans">Plans &amp; pricing</a></dd>
        <dd><a href="http://octodex.github.com/">The Octodex</a></dd>
      </dl>

      <hr class="footer-divider">


    <p class="right">&copy; 2013 <span title="0.35030s from fe17.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    <a class="left" href="https://github.com/">
      <span class="mega-icon mega-icon-invertocat"></span>
    </a>
    <ul id="legal">
        <li><a href="https://github.com/site/terms">Terms of Service</a></li>
        <li><a href="https://github.com/site/privacy">Privacy</a></li>
        <li><a href="https://github.com/security">Security</a></li>
    </ul>

  </div><!-- /.container -->

</div><!-- /.#footer -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
          <div class="suggester-container">
              <div class="suggester fullscreen-suggester js-navigation-container" id="fullscreen_suggester"
                 data-url="/jahennen/CSS_343/suggestions/commit/2dab9dabe4d6885cb194309ddfb8efd0704f6a1a">
              </div>
          </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped leftwards" title="Exit Zen Mode">
      <span class="mega-icon mega-icon-normalscreen"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped leftwards"
      title="Switch themes">
      <span class="mini-icon mini-icon-brightness"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="mini-icon mini-icon-exclamation"></span>
      Something went wrong with that request. Please try again.
      <a href="#" class="mini-icon mini-icon-remove-close ajax-error-dismiss"></a>
    </div>

    
    
    <span id='server_response_time' data-time='0.35089' data-host='fe17'></span>
    
  </body>
</html>

