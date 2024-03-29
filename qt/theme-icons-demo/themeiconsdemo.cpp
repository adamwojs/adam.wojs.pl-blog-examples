#include "themeiconsdemo.h"

ThemeIconsDemo::ThemeIconsDemo(QWidget *parent) :
    QDialog(parent),
    m_iconSize(new QSlider()),
    m_view(new QListView())
{
    const char* icon[] = {
        "address-book-new", "application-exit", "appointment-new", "call-start", "call-stop",
        "contact-new", "document-new", "document-open", "document-open-recent", "document-page-setup",
        "document-print", "document-print-preview", "document-properties", "document-revert", "document-save",
        "document-save", "document-save-as", "document-send", "edit-clear", "edit-copy",
        "edit-cut", "edit-delete", "edit-find", "edit-find-replace", "edit-paste",
        "edit-redo", "edit-select-all", "edit-undo", "folder-new", "format-indent-less",
        "format-indent-more", "format-justify-center", "format-justify-fill", "format-justify-left", "format-justify-right",
        "format-text-direction-ltr", "format-text-direction-rtl", "format-text-bold", "format-text-italic", "format-text-underline",
        "format-text-strikethrough", "go-bottom", "go-down", "go-first", "go-home",
        "go-jump", "go-last", "go-next", "go-previous", "go-top",
        "go-up", "help-about", "help-contents", "help-faq", "insert-image",
        "insert-link", "insert-object", "insert-text", "list-add", "list-remove",
        "mail-forward", "mail-mark-important", "mail-mark-junk", "mail-mark-notjunk", "mail-mark-read",
        "mail-mark-unread", "mail-message-new", "mail-reply-all", "mail-reply-sender", "mail-send",
        "mail-send-receive", "media-eject", "media-playback-pause", "media-playback-start", "media-playback-stop",
        "media-record", "media-seek-backward", "media-seek-forward", "media-skip-backward", "media-skip-forward",
        "object-flip-horizontal", "object-flip-vertical", "object-rotate-left", "object-rotate-right", "process-stop",
        "system-lock-screen", "system-log-out", "system-run", "system-search", "system-reboot",
        "system-shutdown", "tools-check-spelling", "view-fullscreen", "view-refresh", "view-restore",
        "view-sort-ascending", "view-sort-descending", "window-close", "window-new", "zoom-fit-best",
        "zoom-in", "zoom-original", "zoom-out"
    };

    QStandardItemModel *model = new QStandardItemModel();
    for(int i = 0; i < 104; i++) {
        model->appendRow(new QStandardItem(QIcon::fromTheme(icon[i]), icon[i]));
    }
    m_view->setModel(model);

    setupUI();
}

ThemeIconsDemo::~ThemeIconsDemo() {}

void ThemeIconsDemo::iconSizeChanged(int value)
{
    // Ustawiamy rozmiar ikon
    m_view->setIconSize(QSize(value, value));
}

void ThemeIconsDemo::setupUI()
{
    m_iconSize->setOrientation(Qt::Horizontal);
    m_iconSize->setRange(24, 256);
    m_iconSize->setSingleStep(12);
    connect(m_iconSize, SIGNAL(valueChanged(int)), this, SLOT(iconSizeChanged(int)));

    QHBoxLayout *toolbar = new QHBoxLayout();
    toolbar->addWidget(new QLabel(tr("Rozmiar ikon: ")));
    toolbar->addWidget(m_iconSize);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addLayout(toolbar);
    layout->addWidget(m_view);

    setLayout(layout);
    setWindowTitle("Theme Icons Demo");
}
